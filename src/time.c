/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:57:15 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/19 14:15:17 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	start_time(void)
{
	struct timeval	t_init;

	gettimeofday(&t_init, 0);
	return ((t_init.tv_sec * 1000) + (t_init.tv_usec / 1000));
}

long long	timestamp(t_control *table)
{
	struct timeval	current;

	gettimeofday(&current, 0);
	return (((current.tv_sec * 1000) + (current.tv_usec / 1000)) - table->ts);
}

void	ft_sleep(t_philo *p, int t_wait)
{
	long long	time_now;
	long long	diff;

	time_now = timestamp(p->table);
	while (1)
	{
		diff = (timestamp(p->table) - time_now);
		if (diff >= t_wait)
			break ;
		usleep(1000);
	}
}
