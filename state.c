/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:01:49 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/06 07:38:06 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int	sleeping(t_philo *p)
{
	p->state = 'S';
	philo_state((get_now() - p->g_start), p->id, p->state);
	usleep(p->t_sleep * 1000);
	return (0);
}

int	eating(t_philo *p)
{
	p->state = 'E';
	philo_state((get_now() - p->g_start), p->id, p->state);
	p->last_eat = get_now();
	usleep(p->t_eat * 1000);
	pthread_mutex_unlock(&p->fork[p->id - 1]);
	if (p->id != p->max)
		pthread_mutex_unlock(&p->fork[p->id]);
	else
		pthread_mutex_unlock(&p->fork[0]);
	return (0);
}

void	get_fork(t_philo *p)
{
	if (p->id == p->max)
	{
		if (pthread_mutex_lock(&p->fork[p->id - 1]) == 0 && pthread_mutex_lock(&p->fork[0]) == 0)
		{
		p->state = 'F';
		philo_state(get_now() - p->g_start, p->id, p->state);
		philo_state(get_now() - p->g_start, p->id, p->state);
		}
		else
		{
		pthread_mutex_unlock(&p->fork[p->id - 1]);
		pthread_mutex_lock(&p->fork[0]);
		}
	}
	else if (pthread_mutex_lock(&p->fork[p->id - 1]) == 0 && pthread_mutex_lock(&p->fork[p->id]) == 0)
	{
		p->state = 'F';
		philo_state(get_now() - p->g_start, p->id, p->state);
		philo_state(get_now() - p->g_start, p->id, p->state);
	}
	else
	{
		pthread_mutex_unlock(&p->fork[p->id - 1]);
		pthread_mutex_lock(&p->fork[p->id]);
	}
}