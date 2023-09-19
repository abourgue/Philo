/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:17:30 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/19 14:14:19 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philo(t_control *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].meals = 0;
		table->philo[i].t_lastmeal = 0;
		table->philo[i].l_fork = i;
		table->philo[i].r_fork = (i + 1) % table->nb_philo;
		table->philo[i].table = table;
		i++;
	}
}

void	init_table(char **argv, t_control *table)
{
	int	i;

	i = -1;
	table->error = 0;
	table->game_over = 0;
	table->end_meal = 0;
	table->nb_philo = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->max_meals = ft_atoi(argv[5]);
	else
		table->max_meals = 0;
	table->philo = malloc(table->nb_philo * (sizeof(t_philo)));
	table->fork = malloc(table->nb_philo * (sizeof(pthread_mutex_t)));
	pthread_mutex_init(&table->cout, 0);
	pthread_mutex_init(&table->checker, 0);
	while (++i < table->nb_philo)
		pthread_mutex_init(&table->fork[i], 0);
	init_philo(table);
	table->ts = start_time();
}
