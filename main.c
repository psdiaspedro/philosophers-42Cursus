/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:45:15 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/27 19:01:49 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	t_infos infos;
	t_philo *philos;

	validate(argc, argv);
	if(!init(&infos, argc, argv))
		return (0);
	init_philosophers(&infos, &philos);
	start_diner(&infos, philos)
	return (0);
}
