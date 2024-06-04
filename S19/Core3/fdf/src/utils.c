/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:29:49 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/04 17:29:52 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_matrix(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

void	free_iso_matrix(int ***iso_matrix, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < rows)
		{
			if (iso_matrix[i][j] != NULL)
			{
				free(iso_matrix[i][j]);
				iso_matrix[i][j] = NULL;
			}
			++j;
		}
		free(iso_matrix[i]);
		iso_matrix[i] = NULL;
		++i;
	}
	free(iso_matrix);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
