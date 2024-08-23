/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:07:30 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/23 13:07:33 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void    print_status(t_philo *philo, char *action)
{
	char    *color[6];

	color[0] = RED;
	color[1] = GREEN;
	color[2] = YELLOW;
	color[3] = BLUE;
	color[4] = MAGENTA;
	color[5] = CYAN;
	write(1, color[philo->id % 6], ft_strlen(color[philo->id % 6]));
	ft_putnbr_fd(ft_get_time() - philo->start_time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(philo->id, 1);
	write(1, "\t", 1);
	write(1, action, ft_strlen(action));
	write(1, RESET, ft_strlen(RESET));
	write(1, "\n", 1);
}

void    death_bed(int id, long long time)
{
	ft_putnbr_fd(time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(id, 1);
	write(1, "\t", 1);
	write(1, "died", 4);
	write(1, "\n", 1);
}
