/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:34:18 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/20 12:36:05 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philosophers;
	t_philo	*health_monitor;

	philosophers = init_simulation(argc, argv);
	if (!philosophers)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Initialisation of simulation failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	health_monitor = setup_health_monitor(philosophers);
	if (!health_monitor)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Initialisation of the health monitor failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	link_philo_to_monitor(philosophers, health_monitor);
	start_philo_threads(philosophers);
	pthread_create(&health_monitor->philo_thread, NULL,
		check_philo_health, health_monitor);
	pthread_join(health_monitor->philo_thread, NULL);
	return (clean_garbage(philosophers, health_monitor), 0);
}
