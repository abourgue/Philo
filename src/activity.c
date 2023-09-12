/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:25:04 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/12 20:03:07 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_state(t_philo *p)
{
	pthread_mutex_lock(&(p->rules->runningMutex));
	p->running = p->rules->running;
	pthread_mutex_unlock(&(p->rules->runningMutex));
	if (p->running)
		return (0);
	return (1);
}

void	psleep(t_philo *p)
{
	if (check_state(p))
		return;
	printf("%d %d is sleeping\n", ft_time(), p->id);
	usleep(p->rules->t_sleep);
}

void	eat(t_philo *p)
{
	if (check_state(p))
		return ;
	printf("%d %d is thinking\n", ft_time(), p->id);
	pthread_mutex_lock(&p->left_fork);
	pthread_mutex_lock(p->right_fork);
	if (check_state(p))
		return ;
	printf("%d %d has taken a fork\n", ft_time(), p->id);
	printf("%d %d is eating\n", ft_time(), p->id);
	p->last_meal = ft_time();
	p->nbe++;
	usleep(p->rules->t_eat);
	pthread_mutex_unlock(&p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	check_eat(t_philo *p)
{
	if (p->nbe != p->rules->nb_eat || p->rules->nb_eat == -1)
	{
		eat(p);
		if (p->nbe == p->rules->nb_eat)
		{
			pthread_mutex_lock(&(p->rules->runningMutex));
			p->rules->running = 0;
			pthread_mutex_unlock(&(p->rules->runningMutex));
		}
	}
}