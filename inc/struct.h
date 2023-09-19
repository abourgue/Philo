/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:14:25 by jchapell          #+#    #+#             */
/*   Updated: 2023/09/19 14:13:41 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_control	t_control;
typedef struct s_philo		t_philo;

typedef struct s_philo
{
	pthread_t	tid;
	int			id;
	int			meals;
	long long	t_lastmeal;
	int			l_fork;
	int			r_fork;
	t_control	*table;
}	t_philo;

typedef struct s_control
{
	int				nb_philo;
	long long		ts;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	int				max_meals;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	cout;
	pthread_mutex_t	checker;
	int				error;
	int				end_meal;
	int				game_over;
}	t_control;

#endif