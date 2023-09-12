/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:14:25 by jchapell          #+#    #+#             */
/*   Updated: 2023/09/12 19:09:07 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"


typedef struct rules
{
	int					nb_philo;
	int					t_death;
	int					t_eat;
	int					t_sleep;
	int					t_think;
	int					nb_eat;
	int					running;
	pthread_mutex_t		runningMutex;
	pthread_mutex_t		deathMutex;
}			t_rules;

typedef struct philo
{
	int				id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread_id;
	int				last_meal;
	int				philo_ate;
	int				dead;
	int				nbe;
	int				running;
	t_rules			*rules;
}					t_philo;

#endif