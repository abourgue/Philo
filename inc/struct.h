/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:14:25 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 07:21:05 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_philo
{
	int					id;
	char				state;
	int					max;
	unsigned long int	last_eat;
	unsigned long int	philo_start;
	unsigned long int	g_start;
	unsigned long int 	t_eat;
	unsigned long int	t_sleep;
	unsigned long int	t_die;
	pthread_t		p_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*die;
}	t_philo;

typedef struct s_data
{
	int					nb_philo;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		died;
	unsigned long int	t_eat;
	unsigned long int	t_sleep;
	unsigned long int	t_die;
	unsigned long int	t_start;
}	t_data;

#endif