/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:30:55 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/23 13:17:39 by quvan-de         ###   ########.fr       */
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

pthread_mutex_t	*init_forks(int num_philosophers)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);
	if (!forks)
		return (NULL);
	while (i < num_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

long long	*init_last_meal_time(int num_philosophers)
{
	int			i;
	long long	*last_meal_time;

	i = 0;
	last_meal_time = malloc(sizeof(long long) * num_philosophers);
	if (!last_meal_time)
		return (NULL);
	while (i < num_philosophers)
	{
		last_meal_time[i] = ft_get_time();
		i++;
	}
	return (last_meal_time);
}

void	init_philos_data(t_philo *philosophers_initialized,
		t_philo *philo, pthread_mutex_t *num_forks,
		long long *last_meal_time)
{
	int	i;
	int	*meals;

	meals = malloc(sizeof(int) * philo->num_philosophers);
	if (!meals)
		return ;
	memset(meals, 0, sizeof(int) * philo->num_philosophers);
	i = 0;
	while (i < philo->num_philosophers)
	{
		philosophers_initialized[i].id = i + 1;
		philosophers_initialized[i].meals_eaten = meals;
		philosophers_initialized[i].time_to_die = philo->time_to_die;
		philosophers_initialized[i].time_to_eat = philo->time_to_eat;
		philosophers_initialized[i].time_to_sleep = philo->time_to_sleep;
		philosophers_initialized[i].num_must_eat = philo->num_must_eat;
		philosophers_initialized[i].last_meal_time = last_meal_time;
		philosophers_initialized[i].num_forks = philo->num_philosophers;
		philosophers_initialized[i].num_philosophers = philo->num_philosophers;
		philosophers_initialized[i].fork_mutex = num_forks;
		i++;
	}
	free(philo);
}
