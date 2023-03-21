/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:28:52 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 22:45:51 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void* philo_routine(void *arg)
{
  t_philo *philo;
  
  philo = (t_philo *)arg;
  check(philo);
  while (42)
  {
	if (philo->eat_count == philo->table->eat_times)
	  	return (NULL);
	pthread_mutex_lock(&philo->table->death);
    if (philo->table->is_dead == 1)
	{
        break ;
	}
  	pthread_mutex_unlock(&philo->table->death);
	take_fork(philo);
	eat_macaroon(philo);
    philo_sleep(philo);
 	print_state(philo, THINK);
  }
	pthread_mutex_unlock(&philo->table->death);
	return (NULL);
}

void  print_death(t_philo ph)
{
	pthread_mutex_lock(&ph.table->print);
	printf("%ld %d died\n", now(&ph), ph.index);
	pthread_mutex_unlock(&ph.table->print);
}

int meal(t_philo ph)
{
	int status;

	status = ph.eat_count;
	return (status);
}

int  fly_routine(t_table *table)
{
  int i;

  i = 0;
  usleep(100);
  while(42)
  {
	if (i == table->n_philos)
		i = 0;
	if(meal(table->philos[i]) == table->eat_times)
		break ;
    pthread_mutex_lock(&table->l_meal);
    if (now(table->philos) - table->philos[i].last_meal >= table->time_to_die)
    {
      pthread_mutex_lock(&table->death);
      table->is_dead = 1;
      print_death(table->philos[i]);
	  pthread_mutex_unlock(&table->death);
	  pthread_mutex_unlock(&table->l_meal);
      return 1 ; 
    }
	pthread_mutex_unlock(&table->l_meal);
	i++;
	usleep(100);
  }
  return 0;
}

