/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:16:43 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/30 14:10:53 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	destroy_forks(t_philo *philos, t_setup *setup, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < setup->n_of_philos && forks)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(setup->print_locker);
	free(setup->print_locker);
	free(forks);
	free(philos);
	exit(EXIT_FAILURE);
}

void	free_n_destroy_philo(t_philo *philos, t_setup *setup, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < setup->n_of_philos && forks)
	{
		pthread_mutex_destroy(philos[i].meal_locker);
		pthread_mutex_destroy(philos[i].last_meal_locker);
		pthread_mutex_destroy(philos[i].sum_meal_locker);
		pthread_mutex_destroy(philos[i].finish_dinner_locker);
		free(philos[i].meal_locker);
		free(philos[i].last_meal_locker);
		free(philos[i].sum_meal_locker);
		free(philos[i].finish_dinner_locker);
		i++;
	}
	i = 0;
	while (i < setup->n_of_philos && philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(setup->print_locker);
	free(setup->print_locker);
	free(forks);
	free(philos);
	exit(EXIT_FAILURE);
}
