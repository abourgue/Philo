/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:17:30 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/06 07:25:02 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

unsigned long int	get_now(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		return (msg_error("ERR l-19: invalid return gettimeofday()"));
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	*dying(void *ph)
{
	t_philo	*p;

	p = (t_philo *)ph;
	while (p->state != 'D')
	{
		if (get_now() - p->last_eat >= p->t_die)
			p->state = 'D';
	}
	if (pthread_mutex_lock(p->die) == 0)
		philo_state(get_now() - p->g_start, p->id, p->state, ph);	
	exit (0);
	return (0);
}

int	create_philo(t_data *d, int i)
{
	d->philo[i].philo_start = get_now();
	d->philo[i].last_eat = get_now();
	d->philo[i].id = i + 1;
	d->philo[i].state = 'T';
	d->philo[i].g_start = d->t_start;
	d->philo[i].t_die = d->t_die;
	d->philo[i].t_eat = d->t_eat;
	d->philo[i].t_sleep = d->t_sleep;
	d->philo[i].max = d->nb_philo;
	d->philo[i].die = &d->died;
	d->philo[i].mu = &d->mute;
	d->philo[i].fork = d->forks;
	pthread_mutex_init(&d->philo[i].fork[i], NULL);
	if (pthread_create(&d->philo[i].p_thread, NULL, &routine, &d->philo[i])
		|| pthread_create(&d->philo[i].dying, NULL, &dying, &d->philo[i]))
		return(msg_error("ERR util.c(35): pthread_create()"));
	usleep(150);
	return (0);
}

void	init_data(t_data *d, char **value)
{
	d->t_start = get_now();
	d->nb_philo = ft_atoi(value[1]);
	d->t_die = ft_atoi(value[2]);
	d->t_eat = ft_atoi(value[3]);
	d->t_sleep = ft_atoi(value[4]);
	d->philo = malloc(sizeof(t_philo) * d->nb_philo);
	d->forks = malloc(sizeof(pthread_mutex_t) * d->nb_philo);
	pthread_mutex_init(&d->died, NULL);
	pthread_mutex_init(&d->mute, NULL);
}

int exit_die(t_data *d, int index)
{
	int	i;

	i = -1;
	if (pthread_mutex_lock(&d->died) == 0)
		philo_state((get_now() - d->philo[index].g_start), d->philo[index].id,d->philo[index].state, d->philo);
	while (++i < d->nb_philo)
		pthread_mutex_destroy(&d->forks[i]);
	pthread_mutex_destroy(&d->died);
	// free(d->philo);
	free(d->forks);
	exit(0);
}