/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:45:15 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/31 16:47:27 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_setup			setup;
	pthread_mutex_t *forks;
	t_philo			*philo;

	philo = NULL;
	forks = NULL;
	validate(argc, argv);
	init(&setup, &philo, &forks, argv);
	start_dinner(philo, setup.n_of_philos);
	free_finish(philo, &setup, forks);
	return (0);
}
