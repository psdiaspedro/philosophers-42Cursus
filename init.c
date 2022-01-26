/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:43:48 by paugusto          #+#    #+#             */
/*   Updated: 2022/01/25 21:25:33 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	init(t_infos *infos, int argc, char **argv)
{
	infos->n_of_philos = ft_atoi(argv[1]);
	infos->time_to_die = ft_atoi(argv[2]);
	infos->time_to_eat = ft_atoi(argv[3]);
	infos->time_to_eat = ft_atoi(argv[4]);
	if (argv[5])
		infos->must_eat = ft_atoi(argv[5]);
	else
		infos->must_eat = -1;
}
