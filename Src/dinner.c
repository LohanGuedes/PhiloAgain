/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:21:49 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 20:02:54 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  take_fork(t_philo *philo)
{
  if(philo->id % 2 && philo->index != philo->table->n_philos) {
    //Lock
    pthread_mutex_lock(&philo->table->mutexes[philo->l_fork]);
    print_state(philo, TOOK_FORK);

    pthread_mutex_lock(&philo->table->mutexes[philo->r_fork]);
    print_state(philo, TOOK_FORK);
    
  }
  else {
    pthread_mutex_lock(&philo->table->mutexes[philo->r_fork]);
    print_state(philo, TOOK_FORK);
    pthread_mutex_lock(&philo->table->mutexes[philo->l_fork]);
    print_state(philo, TOOK_FORK);
  }
}

void  eat_macaroon(t_philo *philo)
{
  philo->last_meal = get_time_in_ms();
  philo_eat(philo);
  if(philo->id % 2 && philo->index != philo->table->n_philos)
  {
    pthread_mutex_unlock(&philo->table->mutexes[philo->r_fork]);
    pthread_mutex_unlock(&philo->table->mutexes[philo->l_fork]);
  }
  else 
  {
    pthread_mutex_unlock(&philo->table->mutexes[philo->l_fork]);
    pthread_mutex_unlock(&philo->table->mutexes[philo->r_fork]);
  }
}