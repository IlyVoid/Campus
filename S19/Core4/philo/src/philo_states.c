/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:30:07 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/22 17:30:17 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

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
