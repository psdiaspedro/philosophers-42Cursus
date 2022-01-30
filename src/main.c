/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:45:15 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/30 13:24:31 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/* EXTERNAL FUNCTIONS
	memset -> preenche a memoria com bytes
	printf -> printa formatado
	malloc -> aloca memoria
	free -> libera memoria
	write -> escreve no fd
	usleep
	gettimeofday

	pthread_create -> cria uma thread
	pthread_detach
	pthread_join -> basicamente eh o wait para thread, espera acabar
	pthread_mutex_init -> inicia um mutex
	pthread_mutex_destroy -> destroi um mutex
	pthread_mutex_lock -> lock o acesso de outras threads
	pthread_mutex_unlock -> desloca o acesso de outras threads
*/



int	main(int argc, char **argv)
{
	t_setup			setup;
	t_philo 		*philos;
	pthread_mutex_t *forks;

	validate(argc, argv);
	if(!init(&setup, argv))
		return (0);
	init_forks(&setup, &forks);
	init_philosophers(&setup, &philos, &forks);
	start_diner(philos);
	free_n_destroy_philo(philos, &setup, forks);
	return (0);
}
