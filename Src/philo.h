/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:28:37 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/14 05:56:17 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "../Includes/libft/src/libft.h"

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mutex;
typedef struct	s_philo	t_philo;
typedef struct s_philo
{
	pthread_t	thr;
	short		id;
	short		index;
	short		l_fork;
	short		r_fork;
	long int	last_meal;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	short		n_philos;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	short		eat_times;
	long int	current_time;
	t_philo		*philos;
	t_mutex		*mutexes;
}	t_table;

#endif
