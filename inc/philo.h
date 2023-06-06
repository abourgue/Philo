/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:14:25 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 07:30:16 by abourgue         ###   ########.fr       */
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

/*CONSOLE			*/
int			msg_error(char *str);
void		philo_state(unsigned long int time, int philo, char type, t_philo *p);

/*LIB_ITOA			*/
char        *zz_itoa(int n);

/*LIBFT				*/
int         zz_strlen(char *s);
int         ft_atoi(const char *str);

/*MAIN				*/
void        *routine(void *philo);

/*STATE				*/
int         thinking(t_philo *p);
int         sleeping(t_philo *p);
int         eating(t_philo *p);
void        get_fork(t_philo *p);

/*UTILS				*/
void	            *dying(void *ph);
unsigned long int	get_now(void);
int		            create_philo(t_data *d, int index);
void	            init_data(t_data *d, char **value);
int		            exit_die(t_data *d, int index);

#endif