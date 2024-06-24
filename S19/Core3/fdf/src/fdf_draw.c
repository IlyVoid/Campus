/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:49:27 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/24 14:15:22 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_background(t_fdf *fdf, int width, int height, int bg_color)
{
	int	bg_x;
	int	bg_y;

	bg_x = 10;
	bg_y = 10;
	while (bg_y < height)
	{
		bg_x = 10;
		while (bg_x < width)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, bg_x, bg_y, bg_color);
			bg_x++;
		}
		bg_y++;
	}
}

void	display_controls(t_fdf *fdf)
{
	t_controls	ctls;

	ctls.x = 20;
	ctls.y = 20;
	ctls.color = 0xFFFFFF;
	ctls.spacing = 30;
	draw_background(fdf, 300, 250, 0x000000);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		ctls.x, ctls.y, ctls.color, "Controls:");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		ctls.x, ctls.y + ctls.spacing, ctls.color, "Zoom In: +/-");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		ctls.x, ctls.y + 3 * ctls.spacing, ctls.color, "Depth: W/S");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		ctls.x, ctls.y + 5 * ctls.spacing, ctls.color, "Rotate: A/D");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		ctls.x, ctls.y + 7 * ctls.spacing, ctls.color, "Move: Arrow keys");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		ctls.x, ctls.y + 8 * ctls.spacing, ctls.color, "Change Color: C");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		ctls.x, ctls.y + 9 * ctls.spacing, ctls.color, "Exit: ESC");
}

void	draw(t_fdf *fdf)
{
	fdf->dots.y = 0;
	while (fdf->dots.y < fdf->height)
	{
		fdf->dots.x = 0;
		while (fdf->dots.x < fdf->width)
		{
			if (fdf->dots.x < fdf->width - 1)
				bresenham(fdf, fdf->dots.x + 1, fdf->dots.y);
			if (fdf->dots.y < fdf->height - 1)
				bresenham(fdf, fdf->dots.x, fdf->dots.y + 1);
			fdf->dots.x++;
		}
		fdf->dots.y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
	display_controls(fdf);
}
