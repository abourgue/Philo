/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:14:25 by jchapell          #+#    #+#             */
/*   Updated: 2023/09/15 01:59:40 by abourgue         ###   ########.fr       */
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
void		print(t_philo *p, char *state);

/*ACTIVITY			*/
void		*one_philo(void *p);
void		eat(t_philo *ph);
void		think(t_philo *ph);
void		psleep(t_philo *ph);

/*PHILOCONTROL		*/
void		dining(t_control *table);
void		end(t_control *input);

/*TIME				*/
long long	start_time(void);
long long	timestamp(t_control *table);
void		ft_sleep(t_philo *p, int t_wait);

/*init				*/
void		init_table(char **argv, t_control *table);

#endif