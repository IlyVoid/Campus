/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:29:25 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/04 17:29:26 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_params(t_line_params *params)
{
	params->dx = abs(params->x1 - params->x0);
	params->dy = abs(params->y1 - params->y0);
	if (params->x0 < params->x1)
	{
		params->x_direction = 1;
	}
	else
	{
		params->x_direction = -1;
	}
	if (params->y0 < params->y1)
	{
		params->y_direction = 1;
	}
	else
	{
		params->y_direction = -1;
	}
	params->err = params->dx - params->dy;
}

int	get_color(int height)
{
	if (height > 100)
		return (0xFFFFFF);
	else if (height > 50)
		return (0x402400);
	else if (height > 30)
		return (0x9A5700);
	else if (height > 10)
		return (0x009A00);
	else if (height > 0)
		return (0x00FF00);
	else
		return (0x0000FF);
}
