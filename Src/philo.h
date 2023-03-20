/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:28:37 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 20:13:36 by lguedes          ###   ########.fr       */
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

# define TOOK_FORK "%ld %d has taken fork\n"
# define EAT "%ld %d is eating\n"
# define SLEEP "%ld %d is sleeping\n"
# define THINK "%ld %d is thinking\n"
# define DIED "%ld %d died\n" 

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
	short		eat_count;
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
	short		is_dead;
	t_philo		*philos;
	t_mutex		*mutexes;
	t_mutex		print;
}	t_table;


void print_state(t_philo *philo, char *message);
void philo_sleep(t_philo *philo);
void philo_eat(t_philo *philo);
void philo_think(t_philo *philo);
void  take_fork(t_philo *philo);
double  get_time_in_ms(void);
void  eat_macaroon(t_philo *philo);
void  mutexes_init(t_table *table);
void init_philos(t_table *table);
void* philo_routine(void *arg);
double  get_time_in_ms(void);


#endif
