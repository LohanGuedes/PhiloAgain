/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:41:38 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 22:09:28 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_params(int argc, char **argv, t_table *table)
{
	if ((argc == 5 || argc == 6))
	{
		table->eat_times = -1;
		if (argc == 6)
			table->eat_times = ft_atoi(argv[5]);
		table->time_to_die = ft_atoi(argv[2]);
		table->time_to_eat = ft_atoi(argv[3]);
		table->time_to_sleep = ft_atoi(argv[4]);
		table->n_philos = ft_atoi(argv[1]);
		table->philos = malloc(sizeof(t_philo) * table->n_philos);
		table->mutexes = malloc(sizeof(t_mutex) * table->n_philos);
		table->current_time = get_time_in_ms();
		table->is_dead = 0;
	}
	else
	{
		printf("PUT THIS ON STD ERROR: ERROR");
		return (-1);
	}

	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	parse_params(argc, argv, &table);
	mutexes_init(&table);
	init_philos(&table);
	int i = 0;
	while (i < table.n_philos)
		pthread_join(table.philos[i++].thr, NULL);
	return (0);
}
