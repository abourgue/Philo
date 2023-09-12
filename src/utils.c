/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:17:30 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/12 13:46:21 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	create_philo(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->rules->nb_philo)
	{
		p[i].last_meal = 0;
		p[i].rules = p->rules;
		p[i].id = i;
		p[i].dead = 0;
		p[i].nbe = 0;
		pthread_create(&p[i].thread_id, NULL, routine, &p[i]);
		usleep(100);
	}
}

static int	init_time(void)
{
	struct timeval	te;
	int				time;

	gettimeofday(&te, NULL);
	time = 0;
	time += (te.tv_sec * 1000) + (te.tv_usec / 1000);
	return (time);
}

int	ft_time(void)
{
	static int	time;

	if (time == 0)
		time = init_time();
	return (init_time() - time);
}

void	init_rules(t_philo *p, int ac, char **av)
{
	p->rules = malloc(sizeof(t_rules));
	p->rules->nb_philo = ft_atoi(av[1]);
	if (p->rules->nb_philo == 1)
	{
		free(p->rules);
		free(p);
		printf("philo 0 died\n");
		exit(0);
	}
	p->rules->t_death = ft_atoi(av[2]);
	p->rules->t_eat = ft_atoi(av[3]) * 1000;
	p->rules->t_sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		p->rules->nb_eat = ft_atoi(av[5]);
	else
		p->rules->nb_eat = -1;
}

void	init_mut(t_philo *p, int np)
{
	int	i;

	i = 0;
	pthread_mutex_init(&p[i].left_fork, NULL);
	while (++i < np)
	{
		pthread_mutex_init(&p[i].left_fork, NULL);
		p[i].right_fork = &p[i - 1].left_fork;
	}
	p[0].right_fork = &p[i].left_fork;
}
