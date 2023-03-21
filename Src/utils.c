/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:34:13 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 21:45:23 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check(t_philo *philo)
{
	if (philo->id % 2)
		usleep(550);
}

long	now(t_philo *philo)

{
	long	start;
	
	start = philo->table->current_time;
	return (get_time_in_ms() - start);
}

void	sleep_time(long time, t_philo *philo)

{
	long start;

	start = now(philo);
	while (now(philo) - start < time)
		usleep(100);
}
