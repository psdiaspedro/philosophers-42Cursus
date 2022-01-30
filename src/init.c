/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:43:48 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/30 14:10:27 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init(t_setup *setup, char **argv) //init setup
{
	setup->n_of_philos = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		setup->must_eat = ft_atoi(argv[5]);
	if (setup->n_of_philos == 0 || setup->time_to_die == 0
		|| setup->time_to_eat == 0 || setup->time_to_sleep == 0)
		return (0);
	if (argv[5] && setup->must_eat == 0)
		return (0);
	setup->alone_philo = 0;
	setup->first_meal = 0;
	setup->is_dinner_finished = 0;
	if (setup->n_of_philos == 1)
		setup->alone_philo = 1;
	setup->print_locker = malloc(sizeof(pthread_mutex_t));
	if (setup->print_locker == NULL)
	{
		printf("memory allocation fail\n");
		free(setup->print_locker);
	}
	pthread_mutex_init(setup->print_locker, NULL);
	return (1);
}

void	init_forks(t_setup *setup, pthread_mutex_t **forks)
{
	int	i;

	*forks = malloc(sizeof(pthread_mutex_t) * setup->n_of_philos);
	if (*forks == NULL)
	{
		printf("memory allocation fail\n");
		pthread_mutex_destroy(setup->print_locker);
		free(setup->print_locker);
		free(*forks);
	}
	i = 0;
	while (i < setup->n_of_philos)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
}

void	init_philosophers(t_setup *setup, t_philo **philos, pthread_mutex_t **forks)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * setup->n_of_philos); //vetor
	if(*philos == NULL)
	{
		printf("memory allocation fail\n");
		destroy_forks(*philos, setup, *forks);
	}
	i = 0;
	while (i < setup->n_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].left_fork = &(*forks)[i + 1];
		(*philos)[i].right_fork = &(*forks)[i];
		(*philos)[i].meals = 0;
		(*philos)[i].setup = setup;
		(*philos)[i].meal_locker = malloc(sizeof(pthread_mutex_t));
		(*philos)[i].sum_meal_locker = malloc(sizeof(pthread_mutex_t));
		(*philos)[i].last_meal_locker = malloc(sizeof(pthread_mutex_t));
		(*philos)[i].finish_dinner_locker = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((*philos)[i].meal_locker, NULL);
		pthread_mutex_init((*philos)[i].sum_meal_locker, NULL);
		pthread_mutex_init((*philos)[i].last_meal_locker, NULL);
		pthread_mutex_init((*philos)[i].finish_dinner_locker, NULL);
		i++;
	}
	(*philos)[--i].left_fork = &(*forks)[0];
}
