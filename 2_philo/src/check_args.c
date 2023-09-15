/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:36:40 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/14 16:56:53 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_val(int size, char **value)
{
	int	i;
	int	*temp;

	temp = malloc((size - 1) * sizeof(int));
	i = 1;
	while (i < size)
	{
		if (!ft_isnum(value[i]))
		{
			free(temp);
			return (1);
		}
		temp[i - 1] = ft_atoi(value[i]);
		i++;
	}
	free(temp);
	return (0);
}
