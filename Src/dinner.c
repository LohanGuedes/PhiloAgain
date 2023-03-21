/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:21:49 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 22:17:15 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void one_dinner(t_philo *philo)
{
  print_state(philo, TOOK_FORK);
  usleep(philo->table->time_to_die);
  print_death(philo[0]);
}

void  take_fork(t_philo *philo)
{
  if(philo->id % 2 && philo->index != philo->table->n_philos) 
  {
    pthread_mutex_lock(&philo->table->mutexes[philo->l_fork]);
    print_state(philo, TOOK_FORK);
    pthread_mutex_lock(&philo->table->mutexes[philo->r_fork]);
    print_state(philo, TOOK_FORK);
  }
  else 
  {
    pthread_mutex_lock(&philo->table->mutexes[philo->r_fork]);
    print_state(philo, TOOK_FORK);
    pthread_mutex_lock(&philo->table->mutexes[philo->l_fork]);
    print_state(philo, TOOK_FORK);
  }
}

void  eat_macaroon(t_philo *philo)
{
  pthread_mutex_lock(&philo->table->l_meal);
  philo->last_meal = now(philo);
  philo->eat_count++;
  pthread_mutex_unlock(&philo->table->l_meal);
  philo_eat(philo);
  if (philo->id % 2 && philo->index != philo->table->n_philos)
  {
    pthread_mutex_unlock(&philo->table->mutexes[philo->l_fork]);
    printf("OI PORRA\n");
    pthread_mutex_unlock(&philo->table->mutexes[philo->r_fork]);
  }
  else 
  {
    pthread_mutex_unlock(&philo->table->mutexes[philo->r_fork]);
    pthread_mutex_unlock(&philo->table->mutexes[philo->l_fork]);
  }
}