/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:50:57 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/27 18:52:31 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int mail = 0;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
		mail++;
	return (NULL);
}

void	start_diner(t_infos *infos, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < infos->n_of_philos)
		pthread_create(&philos[i].thread, NULL, &routine, NULL);
	i = 0;
	while (i < infos->n_of_philos)
		pthread_join(philos[i].thread, NULL);
}
