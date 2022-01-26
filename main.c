/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:45:15 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/25 21:24:29 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* EXTERNAL FUNCTIONS

	memset
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
	pthread_mutex_lock
	pthread_mutex_unlock
*/

int	main(int argc, char **argv)
{
	t_infos infos;
	
	validate(argc, argv);
	init(infos, argc, argv)

	return (0);
}
