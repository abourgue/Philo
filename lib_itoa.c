/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 04:55:16 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/06 04:56:08 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

static int	ft_abs(int d)
{
	if (d < 0)
		d *= -1;
	return (d);
}

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb = nb * ft_power(nb, power - 1);
	return (nb);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	memset(ptr, '\0', size * count);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (zz_strlen(s1) + 1));
	if (!res)
		return (0);
	while (i < (int)zz_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*zz_itoa(int n)
{
	int		nbzero;
	int		n2;
	char	*res;
	int		i;

	nbzero = 1;
	n2 = n;
	i = 0;
	if (n == -2147483648 && nbzero++)
		n2 = n / 10;
	while (ft_abs(n2) > 9 && nbzero++)
		n2 = n2 / 10;
	if (n == 0)
		return (ft_strdup("0"));
	res = ft_calloc(sizeof(char) * nbzero + 2, sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
		res[i++] = '-';
	while (--nbzero >= 0)
	{
		res[i++] = ft_abs((n / ft_power(10, nbzero))) + 48;
		n = n - ((n / ft_power(10, nbzero)) * ft_power(10, nbzero));
	}
	return (res);
}