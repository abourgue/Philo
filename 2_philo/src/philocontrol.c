/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philocontrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:53:23 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/15 02:19:07 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	check_death(t_philo *p)
{
	pthread_mutex_lock(&p->table->checker);
	if ((timestamp(p->table) - p->t_lastmeal) >= p->table->t_die)
	{
		print(p, "died");
		p->table->game_over = 1;
	}
	pthread_mutex_unlock(&p->table->checker);
}

void	checker(t_control *c)
{
	int	meal_i;
	int	death_i;

	meal_i = 0;
	death_i = 0;
	while (c->game_over == 0)
	{
		check_death(&c->philo[death_i]);
		if (c->max_meals > 0)
		{
			while (meal_i < c->nb_philo)
			{
				if (c->philo[meal_i].meals < c->max_meals)
					break ;
				meal_i++;
			}
			if (meal_i == c->nb_philo)
				c->game_over = 1;
		}
		usleep(5000);
		if (death_i == c->nb_philo -1)
			death_i = -1;
		death_i++;
	}
}

void	*routine(void *p)
{
	t_philo		*ph;
	t_control	*input;

	ph = (t_philo *)p;
	input = ph->table;
	if (ph->id % 2)
		usleep(1500);
	while (input->game_over == 0)
	{
		if (input->max_meals > 0 && ph->meals == input->max_meals)
			break ;
		eat(ph);
		psleep(ph);
		think(ph);
	}
	return (0);
}

void	dining(t_control *table)
{
	int		i;

	if (table->nb_philo == 1)
		one_philo(table->philo);
	else
	{
		i = -1;
		while (++i < table->nb_philo)
			pthread_create(&table->philo[i].tid, 0, \
			&routine, (void *) &table->philo[i]);
		while (table->game_over == 0)
			checker(table);
	}
}

void	end(t_control *input)
{
	int	i;

	i = input->nb_philo;
	while (--i >= 0)
		pthread_join(input->philo[i].tid, 0);
	while (++i < input->nb_philo)
		pthread_mutex_destroy(&input->fork[i]);
	pthread_mutex_destroy(&input->cout);
	pthread_mutex_destroy(&input->checker);
	free(input->philo);
	free(input->fork);
	free(input);
}