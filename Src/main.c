/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:41:38 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/13 23:35:17 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  *routine() {
  printf("Hello, World!\n");
  sleep(3);
  printf("Thread ended\n");
  return (NULL);
}

int main(int argc, char **argv) {
  int remaining_eat_times;

  if (argc != 4) {
         
    return 0;
  }
  if (argc == 5) {
    remaining_eat_times = atoi(argv[4]);
  }


  return 0;
}