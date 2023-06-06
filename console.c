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

void	philo_state(unsigned long int time, int philo, char type, t_philo *p)
{
	(void) p;
		if (type == 'F')
			printf("%lums %d\thas taken a fork\n", time, philo);
		else if (type == 'E')
			printf("%lums %d\tis eating\n", time, philo);
		else if (type == 'S')
			printf("%lums %d\ttis sleeping\n", time, philo);
		else if (type == 'T')
			printf("%lums %d\tis thinking\n", time, philo);
		else if (type == 'D')
			{
				printf("%lums %d\tdied\n", time, philo);
				exit (0);
			}
}