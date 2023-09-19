/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:25:04 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/19 14:11:25 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*one_philo(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	pthread_mutex_lock(&ph->table->fork[ph->l_fork]);
	print(ph, "has taken a fork");
	pthread_mutex_lock(&ph->table->checker);
	ph->t_lastmeal = timestamp(ph->table);
	pthread_mutex_unlock(&ph->table->checker);
	ft_sleep(ph, ph->table->t_die);
	print(ph, "died ");
	ph->table->game_over = 0;
	return (0);
}

void	eat(t_philo *ph)
{
	if (ph->table->game_over == 0)
	{
		pthread_mutex_lock(&ph->table->fork[ph->l_fork]);
		print(ph, "has taken a fork");
		pthread_mutex_lock(&ph->table->fork[ph->r_fork]);
		print(ph, "has taken a fork");
		print(ph, "is eating");
		pthread_mutex_lock(&ph->table->checker);
		ph->t_lastmeal = timestamp(ph->table);
		pthread_mutex_unlock(&ph->table->checker);
		ph->meals += 1;
		ft_sleep(ph, ph->table->t_eat);
		pthread_mutex_unlock(&ph->table->fork[ph->l_fork]);
		pthread_mutex_unlock(&ph->table->fork[ph->r_fork]);
	}
}

void	think(t_philo *ph)
{
	if (ph->table->game_over == 0)
		print(ph, "is thinking");
}

void	psleep(t_philo *ph)
{
	if (ph->table->game_over == 0)
	{
		print(ph, "is sleeping");
		ft_sleep(ph, ph->table->t_sleep);
	}
}
