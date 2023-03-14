/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 06:17:47 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/14 07:11:15 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

double  get_time_in_ms(void)
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
  printf(message, get_time_in_ms(), philo->index);
}

void philo_sleep(t_philo *philo)
{
  print_state(philo, SLEEP);
  usleep(philo->table->time_to_sleep * 1000);
}

void philo_eat(t_philo *philo)
{
  print_state(philo, EAT);
  usleep(philo->table->time_to_eat * 1000);
}

void philo_think(t_philo *philo)
{
  print_state(philo, THINK);
  return ;
}