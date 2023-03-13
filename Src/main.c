/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:41:38 by lguedes           #+#    #+#             */
/*   Updated: 2023/03/13 08:41:40 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft/src/libft.h"
#include "philo.h"

void  *routine() {
  printf("Hello, World!\n");
  sleep(3);
  printf("Thread ended");
  return (NULL);
}

int main(void) {
  pthread_t t1, t2, t3;
  pthread_create(&t1, NULL, &routine, NULL);
  pthread_create(&t2, NULL, &routine, NULL);
  pthread_create(&t3, NULL, &routine, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  return 0;
}