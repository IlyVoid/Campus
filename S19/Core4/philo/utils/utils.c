/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:07:38 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/23 13:09:25 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(long long time)
{
	long long	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time < time)
		usleep(100);
}

void	clean_garbage(t_philo *philosophers, t_philo *health_monitor)
{
	int	i;

	i = 0;
	ft_sleep(philosophers->time_to_die + philosophers->time_to_eat
		+ philosophers->time_to_sleep + 100);
	while (i < philosophers->num_philosophers)
	{
		pthread_mutex_destroy(&philosophers[i].fork_mutex[i]);
		pthread_mutex_destroy(philosophers[i].protection_mutex);
		i++;
	}
	pthread_mutex_destroy(health_monitor->protection_mutex);
	free(philosophers->fork_mutex);
	free(philosophers->meals_eaten);
	free(philosophers->last_meal_time);
	free(philosophers->protection_mutex);
	free(philosophers);
	philosophers = NULL;
	free(health_monitor);
}
