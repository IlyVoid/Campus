/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:07:17 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/23 17:13:16 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void	ft_error_parse_msg(void)
{
	write(2, RED, ft_strlen(RED));
	ft_putstr_fd("Error: invalid argument count\n", 2);
	write(2, RESET, ft_strlen(RESET));
	write(2, GREEN, ft_strlen(GREEN));
	ft_putstr_fd("Usage: ./philo [philo count] [time till death] ", 2);
	ft_putstr_fd("[time to eat] [time to sleep] (+ optional)", 2);
	ft_putstr_fd("[obligated meal count per philo]\n", 2);
	write(2, RESET, ft_strlen(RESET));
	write(2, YELLOW, ft_strlen(YELLOW));
	ft_putstr_fd("Example: ./philo 4 300 200 200 2\n", 2);
	write(2, RESET, ft_strlen(RESET));
}

bool	parse_arguments(int argc, char **argv, t_philo *philo_info)
{
	if (argc < 5 || argc > 6)
	{
		ft_error_parse_msg();
		return (false);
	}
	if (!validate_num_philosophers(argv[1])
		|| !validate_time_argument(argv[2])
		|| !validate_time_argument(argv[3])
		|| !validate_time_argument(argv[4])
		|| (argc == 6 && !validate_num_must_eat(argv[5])))
		return (false);
	philo_info->num_philosophers = ft_atoi(argv[1]);
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->num_must_eat = ft_atoi(argv[5]);
	else
		philo_info->num_must_eat = -1;
	return (true);
}
