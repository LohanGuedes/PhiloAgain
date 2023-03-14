/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:39:18 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/14 06:09:17 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philos(t_table *table)
{
  int offset;

  offset = -1;
  while(++offset < table->n_philos)
  {
    table->philos[offset].id = offset;
    table->philos[offset].index = offset + 1;
    table->philos[offset].l_fork = offset; 
    table->philos[offset].r_fork = offset + 1;
    if (offset == table->n_philos - 1)
      table->philos[offset].r_fork = 0;
    table->philos[offset].last_meal = 0;
    table->philos[offset].table = table;
  }
}