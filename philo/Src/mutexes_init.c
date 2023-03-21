/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:31:45 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 21:46:17 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  mutexes_init(t_table *table)
{
  int offset;

  offset = -1;
  pthread_mutex_init(&table->print, NULL);
  pthread_mutex_init(&table->death, NULL);
  pthread_mutex_init(&table->l_meal, NULL);
  while(++offset < table->n_philos)
    pthread_mutex_init(&table->mutexes[offset], NULL);
}