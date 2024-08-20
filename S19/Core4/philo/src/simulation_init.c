/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:08:55 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/20 15:33:04 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

t_philo	*init_simulation(int argc, char **argv)
{
	t_philo	*philo_info;
	t_philo	*philo_initialised;

	philo_info = malloc(sizeof(t_philo));
	if (!philo_info)
		return (NULL);
	if (!parse_arguments(argc, argv, philo_info))
	{
		free(philo_info);
		return (NULL);
	}
	philo_initialised = init_philosophers(philo_info);
	if (!philo_initialised)
	{
		free(philo_initialised);
		return (NULL);
	}
	return (philo_initialised);
}

t_philo	*init_philosophers(t_philo *philo_info)
{
	t_philo			*philos_initialised;
	pthread_mutex_t	*forks;
	long long		*last_meal_time;

	philos_initialised = malloc(sizeof(t_philo) * philo_info->num_philosophers);
	if (!philos_initialised)
		return (NULL);
	forks = init_forks(philo_info->num_philosophers);
	last_meal_time = init_last_meal_time(philo_info->num_philosophers);
	init_philos_data(philos_initialised, philo_info, forks, last_meal_time);
	return (philos_initialised);
}
