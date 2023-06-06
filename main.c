/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:23:43 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/06 07:32:40 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (p->state != 'D')
	{
		while (p->state != 'F')
			get_fork(p);
		if (p->state == 'F')
			eating(p);
		if (p->state == 'E')
			sleeping(p);
		if (p->state == 'S')
			thinking(p);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
		return (msg_error("ERR: invalid num args"));
	if (check_val(argc, argv))
		return (msg_error("ERR: invalid value"));
	init_data(&data, argv);
	i = -1;
	while (++i < data.nb_philo)
	{
		if (create_philo(&data, i))
			return (1);
	}
	i = 0;
	while (1)
	{
		// if (i == data.nb_philo)
		// 	i = 0;
		// if (data.philo[i].state == 'D' || get_now() - data.philo[i].last_eat >= data.t_die * 1000)
		// {
		// 	data.philo[i].state = 'D';
		// 	exit_die(&data, i);
		// }
		// else
		// 	i++;
		i++;
	}
	return (0);
}