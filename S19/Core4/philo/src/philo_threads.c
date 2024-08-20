/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:54:13 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/20 15:06:34 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"
#include <pthread.h>

void	*philo_lifecycle(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 == 0)
		ft_sleep(10);
	while (1)
	{
		get_fork(philosopher);
		start_eating(philosopher);
		release_forks(philosopher);
		start_sleeping(philosopher);
		start_thinking(philosopher);
	}
}

void	start_philo_threads(t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers->num_philosophers)
	{
		philosophers[i].start_time = ft_get_time();
		pthread_create(&philosophers[i].philo_thread, NULL,
			philo_lifecycle, &philosophers[i]);
		pthread_detach(philosophers[i].philo_thread);
		i++;
	}
}
