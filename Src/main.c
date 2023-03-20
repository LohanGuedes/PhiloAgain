/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:41:38 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/20 20:11:28 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * parse params will return -1 in case of use-error and the number of philos
 * if the parse is succedded 
 */
int	parse_params(int argc, char **argv, t_table *table)
{
/* 	if (!(argc != 5 || argc != 6))
	{
		printf("PUT THIS ON STD ERROR: ERROR");
		return (-1);
	} */
	table->eat_times = -1;
	if (argc == 6)
		table->eat_times = ft_atoi(argv[5]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->n_philos = ft_atoi(argv[1]);
	table->philos = malloc(sizeof(t_philo) * table->n_philos);
	table->mutexes = malloc(sizeof(t_mutex) * table->n_philos);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	table = (t_table){0};
	parse_params(argc, argv, &table);
	mutexes_init(&table);
	init_philos(&table);
	// Call fly -> Check for "zombie" threads?
	return (0);
}
