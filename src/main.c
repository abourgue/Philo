/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:23:43 by abourgue          #+#    #+#             */
/*   Updated: 2023/09/19 14:11:53 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_control	*table;

	if (check_val(argc, argv) != 0)
		return (-1);
	table = (t_control *)malloc(1 * sizeof(t_control));
	if (!table)
		return (-1);
	init_table(argv, table);
	dining(table);
	end(table);
	return (0);
}
