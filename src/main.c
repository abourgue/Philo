/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:23:43 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/12 13:56:35 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg;
	while (p->dead == 0)
	{
		check_eat(p);
		psleep(p);
		if ((ft_time() - p->last_meal) > p->rules->t_death)
		{
			if (p->dead == 0)
			{
				p->dead = 1;
				printf("%d %d died\n", ft_time(), p->id);
			}
			break ;
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
	ft_time();
	create_philo(p);
	while (1)
		checker(p);
	return (0);
}

void	checker(t_philo *p)
{
	int	i;

	i = 0;
	while (1)
	{
		if (p[i].dead == 1)
		{
			i = 0;
			while (i < p->rules->nb_philo)
				p[i++].dead = 1;
			end(p);
		}
		if (i == p->rules->nb_philo)
			i = 0;
		else
			i++;
	}
}

void	end(t_philo *p)
{
	int		i;
	int		nb;

	i = 0;
	nb = p->rules->nb_philo;
	while (++i < nb)
		pthread_mutex_destroy(&p[i].left_fork);
	free(p->rules);
	free(p);
	exit(0);
}

int	msg_error(char *str)
{
	printf("%s\n", str);
	return (1);
}