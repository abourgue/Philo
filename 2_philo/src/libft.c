/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:42:36 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/14 23:19:26 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	zz_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	char	*lst;
	int		neg;
	long	res;
	int		i;

	lst = (char *)str;
	neg = 1;
	res = 0;
	i = 0;
	while (lst[i] == ' ' || lst[i] == '\n' || lst[i] == '\t' || lst[i] == '\v'
		|| lst[i] == '\f' || lst[i] == '\r')
		i++;
	if (lst[i] == '-' || lst[i] == '+')
	{
		if (lst[i] == '-')
			neg *= -1;
		i++;
	}
	while (lst[i] >= 48 && lst[i] <= 57)
	{
		res = res * 10 + (lst[i] - 48);
		lst++;
	}
	return (res * neg);
}

void	print(t_philo *p, char *state)
{
	if (p->table->game_over == 0)
	{
		pthread_mutex_lock(&p->table->cout);
		printf("%lld\t%d\t%s\n", timestamp(p->table), p->id, state);
		pthread_mutex_unlock(&p->table->cout);
	}
}