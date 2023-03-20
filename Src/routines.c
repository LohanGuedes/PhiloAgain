/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:28:52 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 20:03:32 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void* philo_routine(void *arg)
{
  t_philo *philo;
  
  philo = (t_philo *)arg;

  if (philo->id % 2)
    usleep(550);
  while (42)
  {
    if (philo->table->is_dead)
      break ;
	take_fork(philo);
	eat_macaroon(philo);
	philo_sleep(philo);
	philo_think(philo);
  }
  
  return (NULL);
}


/*
	I want to be the fly to land on your soup
          - Raul Seixas
void  fly_routine(void *)
{
  
}
*/
