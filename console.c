/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:25:44 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/06 07:22:30 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int	msg_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void	philo_state(unsigned long int time, int philo, char type)
{
	if (type == 'F')
		printf("%lu %d has taken a fork\n", time, philo);
	else if (type == 'E')
		printf("%lu %d is eating\n", time, philo);
	else if (type == 'S')
		printf("%lu %d is sleeping\n", time, philo);
	else if (type == 'T')
		printf("%lu %d is thinking\n", time, philo);
	else if (type == 'D')
		printf("%lu %d  died\n", time, philo);
}