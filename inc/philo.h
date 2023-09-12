/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:14:25 by jchapell          #+#    #+#             */
/*   Updated: 2023/09/12 13:57:39 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include "struct.h"

/*CHECK_ARGS		*/
int			check_val(int size, char **value);

/*LIBFT				*/
int         zz_strlen(char *s);
int         ft_atoi(const char *str);

/*MAIN				*/
void        *routine(void *philo);
void		checker(t_philo *p);
void		end(t_philo *p);
int			msg_error(char *str);

/*ACTIVITY			*/
void		psleep(t_philo *p);
void		check_eat(t_philo *p);

/*UTILS				*/
void				create_philo(t_philo *p);
int					ft_time(void);
void	            init_rules(t_philo *p, int ac, char **av);
void				init_mut(t_philo *p, int np);

#endif