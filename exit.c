/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:16:43 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/31 16:46:28 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_setup *setup)
{
	free(setup->print_locker);
	free(setup->get_last_meal_locker);
	free(setup->died_locker);
	free(setup->sum_meals_locker);
	free(setup->get_meals_locker);
	free(setup->is_philo_died_locker);
	free(setup->last_meal_locker);
	exit(EXIT_FAILURE);
}

void	free_forks_destroy_mutex(t_setup *setup, pthread_mutex_t *forks)
{
	pthread_mutex_destroy(setup->print_locker);
	pthread_mutex_destroy(setup->get_last_meal_locker);
	pthread_mutex_destroy(setup->died_locker);
	pthread_mutex_destroy(setup->sum_meals_locker);
	pthread_mutex_destroy(setup->get_meals_locker);
	pthread_mutex_destroy(setup->is_philo_died_locker);
	pthread_mutex_destroy(setup->last_meal_locker);
	free(forks);
	free_mutex(setup);
}

void	free_philo(t_philo *philo, t_setup *setup, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < setup->n_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(philo);
	free_forks_destroy_mutex(setup, forks);
}

void	free_finish(t_philo *philo, t_setup *setup, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < setup->n_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(setup->print_locker);
	pthread_mutex_destroy(setup->get_last_meal_locker);
	pthread_mutex_destroy(setup->died_locker);
	pthread_mutex_destroy(setup->sum_meals_locker);
	pthread_mutex_destroy(setup->get_meals_locker);
	pthread_mutex_destroy(setup->is_philo_died_locker);
	pthread_mutex_destroy(setup->last_meal_locker);
	free(setup->print_locker);
	free(setup->get_last_meal_locker);
	free(setup->died_locker);
	free(setup->sum_meals_locker);
	free(setup->get_meals_locker);
	free(setup->is_philo_died_locker);
	free(setup->last_meal_locker);
	free(philo);
	free(forks);
}
