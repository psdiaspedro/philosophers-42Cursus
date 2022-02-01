/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:43:48 by paugusto          #+#    #+#             */
/*   Updated: 2022/02/01 11:00:39 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_setup(t_setup *setup, char	**argv)
{
	setup->n_of_philos = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	setup->must_eat = -1;
	if (argv[5])
		setup->must_eat = ft_atoi(argv[5]);
	setup->first_meal = 0;
	setup->one_philo = 0;
	if (setup->n_of_philos == 1)
		setup->one_philo = 1;
	setup->philo_died = 0;
}

void	init_mutex(t_setup *setup)
{
	setup->print_locker = malloc(sizeof(pthread_mutex_t));
	setup->get_last_meal_locker = malloc(sizeof(pthread_mutex_t));
	setup->died_locker = malloc(sizeof(pthread_mutex_t));
	setup->sum_meals_locker = malloc(sizeof(pthread_mutex_t));
	setup->get_meals_locker = malloc(sizeof(pthread_mutex_t));
	setup->is_philo_died_locker = malloc(sizeof(pthread_mutex_t));
	setup->last_meal_locker = malloc(sizeof(pthread_mutex_t));
	if (setup->print_locker == NULL || setup->get_last_meal_locker == NULL
		|| setup->died_locker == NULL || setup->sum_meals_locker == NULL
		|| setup->get_meals_locker == NULL || setup->last_meal_locker == NULL
		|| setup->is_philo_died_locker == NULL)
		free_mutex(setup);
	pthread_mutex_init(setup->print_locker, NULL);
	pthread_mutex_init(setup->get_last_meal_locker, NULL);
	pthread_mutex_init(setup->died_locker, NULL);
	pthread_mutex_init(setup->sum_meals_locker, NULL);
	pthread_mutex_init(setup->get_meals_locker, NULL);
	pthread_mutex_init(setup->is_philo_died_locker, NULL);
	pthread_mutex_init(setup->last_meal_locker, NULL);
}

void	init_forks(t_setup *setup, pthread_mutex_t **forks, int n_of_philos)
{
	int	i;

	*forks = malloc(sizeof(pthread_mutex_t) * n_of_philos);
	if (*forks == NULL)
		free_forks_destroy_mutex(setup, *forks);
	i = 0;
	while (i < n_of_philos)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
}

void	init_philos(t_philo **philo, t_setup *setup, pthread_mutex_t **forks)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * setup->n_of_philos);
	if (philo == NULL)
		free_philo(*philo, setup, *forks);
	i = 0;
	while (i < setup->n_of_philos)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_meal = 0;
		(*philo)[i].meals = 0;
		(*philo)[i].right_fork = &(*forks)[i];
		(*philo)[i].left_fork = &(*forks)[i + 1];
		(*philo)[i].setup = setup;
		i++;
	}
	i--;
	(*philo)[i].left_fork = &(*forks)[0];
}

void	init(t_setup *set, t_philo **phi, pthread_mutex_t **forks, char **argv)
{
	init_setup(set, argv);
	init_mutex(set);
	init_forks(set, forks, set->n_of_philos);
	init_philos(phi, set, forks);
}
