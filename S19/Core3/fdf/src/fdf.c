/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:49:20 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/24 12:49:22 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	destroy(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(0);
}

int	main(int argc, char **argv)

{
	t_fdf	fdf;

	if (input_check(argc, argv[1]))
		return (1);
	read_file(&fdf, argv[1]);
	minilibx_init(&fdf, argv[1]);
	fdf_init(&fdf);
	image_init(&fdf);
	mlx_hook(fdf.win_ptr, 2, 1l, key_hook, &fdf);
	mlx_hook(fdf.win_ptr, 17, 1l << 15, destroy, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
