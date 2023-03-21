/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 06:17:47 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 22:46:15 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long  get_time_in_ms(void)
{
  struct timeval tp;
  long   ms; 

  gettimeofday(&tp, NULL);
  ms = tp.tv_sec * 1000;
  ms += tp.tv_usec / 1000;
  return (ms);
}

void print_state(t_philo *philo, char *message)
{
  
  pthread_mutex_lock(&philo->table->death);
  pthread_mutex_lock(&philo->table->print);
  if (philo->table->is_dead == 0)
    printf("%ld %d %s\n",now(philo), philo->index, message);
  pthread_mutex_unlock(&philo->table->print);
  pthread_mutex_unlock(&philo->table->death);
}

void philo_sleep(t_philo *philo)
{
  print_state(philo, SLEEP);
  sleep_time(philo->table->time_to_sleep, philo);
}

void philo_eat(t_philo *philo)
{
  print_state(philo, EAT);
  sleep_time(philo->table->time_to_eat, philo);
}
