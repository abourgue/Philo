/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:23:43 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/14 19:28:42 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg;
	while (p->running)
	{
		check_eat(p);
		psleep(p);
		if ((ft_time() - p->last_meal) > p->rules->t_death && p->running)
		{
			pthread_mutex_lock(&(p->rules->runningMutex));
			if (p->rules->running == 1)
			{
				p->rules->running = 0;
				printf("%d %d died\n", ft_time(), p->id);
			}
			pthread_mutex_unlock(&(p->rules->runningMutex));
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*p;

	if (argc < 5 || argc > 6)
		return (msg_error("ERR: invalid num args"));
	if (check_val(argc, argv))
		return (msg_error("ERR: invalid value"));
	p = malloc(sizeof(t_philo) * (ft_atoi(argv[1]) + 1));
	if (!p)
		return (1);
	init_rules(p, argc, argv);
	init_mut(p, p->rules->nb_philo);
	create_philo(p);
	checker(p);
	return (0);
}

void	checker(t_philo *p)
{
	while (1)
	{
		pthread_mutex_lock(&(p->rules->runningMutex));
		if (p->rules->running == 0)
		{
			end(p);
			break ;
		}
		pthread_mutex_unlock(&(p->rules->runningMutex));
	}
}

void	end(t_philo *p)
{
	int		i;
	void	**ret;

	ret = NULL;
	i = -1;
	pthread_mutex_unlock(&(p->rules->runningMutex));
	while (++i < p->rules->nb_philo)
	{
		pthread_mutex_destroy(&p[i].left_fork);
		pthread_join(p[i].thread_id, ret);
	}
	pthread_mutex_destroy(&(p->rules->runningMutex));
	free(p->rules);
	free(p);
	exit(0);
}

int	msg_error(char *str)
{
	printf("%s\n", str);
	return (1);
}
