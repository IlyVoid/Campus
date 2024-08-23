/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:29:29 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/23 17:17:42 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void	get_fork(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 1]);
	if (philosopher->id == 1)
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher
			->num_philosophers - 1]);
	else
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 2]);
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "has taken a fork");
	pthread_mutex_unlock(philosopher->protection_mutex);
}

void	start_eating(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is eating");
	philosopher->last_meal_time[philosopher->id - 1] = ft_get_time();
	philosopher->meals_eaten[philosopher->id - 1]++;
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_eat);
}

void	release_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 1]);
	if (philosopher->id == 1)
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher
			->num_philosophers - 1]);
	else
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 2]);
}
