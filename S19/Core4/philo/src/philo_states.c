/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:49:27 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/20 14:53:59 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"
#include <pthread.h>

void	start_sleeping(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is sleeping");
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_sleep);
}

void	start_thinking(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is thinking");
	pthread_mutex_unlock(philosopher->protection_mutex);
}
