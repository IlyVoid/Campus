/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:01:56 by quvan-de          #+#    #+#             */
/*   Updated: 2024/05/17 10:02:55 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common/common.h"

void	read_args(int argc, char **argv, t_mem *mem)
{
	int	j;
	int	i;
	int	prev_space;

	i = 1;
	prev_space = 1;
	while (i < argc)
	{
		prev_space = 1;
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' '
				&& !ft_isdigit(argv[i][j]))
				exit_error(mem);
			if (prev_space == 1 && argv[i][j] != ' ')
			{
				push_init(&(mem->a), ft_atoi(argv[i] + j, mem), -1, mem);
				prev_space = 0;
			}
			prev_space = argv[i][j] == ' ';
		}
		i++;
	}
}
