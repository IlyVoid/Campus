/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:49:03 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/24 15:48:15 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdint.h>
# include "get_next_line.h"

# define WIDTH 1200
# define HEIGHT 1000

# define YELLOW 0x00FFFF66 
# define BLUE 0x0099CCFF
# define GREEN 0x0099FF33
# define VIOLET 0x00CC99FF
# define CYAN 0x0000FFFF
# define ROSE 0x00FF00CC    
# define DARKBLUE 0x006633CC

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define Z_UP 119 // W
# define Z_DOWN 115 // S
# define ANGLE_LEFT 97 // A
# define ANGLE_RIGHT 100 // D
# define COLOR 99 // C
# define TOP 116 // T

typedef struct s_rgb
{
	uint8_t		r1;
	uint8_t		r2;
	uint8_t		g1;
	uint8_t		g2;
	uint8_t		b1;
	uint8_t		b2;
}				t_rgb;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_coordinates
{
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
	float		x_step;
	float		y_step;
}				t_coordinates;

typedef struct s_dots
{
	int			x;
	int			y;
}				t_dots;

typedef struct s_controls
{
	int			x;
	int			y;
	int			color;
	int			spacing;
}				t_controls;

typedef struct s_fdf
{
	int			width;
	int			height;
	int			**matrix;
	float		zoom;
	uint64_t	color;
	int			color_flag;
	int			isometric_flag;
	int			z_shift;
	int			shift_x;
	int			shift_y;
	double		angle;
	void		*mlx_ptr;
	void		*win_ptr;
	t_dots		dots;
	t_data		img;
}				t_fdf;

/*_________________________/fdf_error.c/_________________________*/
void	ft_error(char *str);
int		input_check(int argc, char *file);
/*_________________________/read_file/_________________________*/
void	read_file(t_fdf *fdf, char *file_name);
void	get_height_and_width(t_fdf *fdf, char *file_name);
void	fill_matrix(t_fdf *fdf, char *file_name);
/*_________________________/init.c/_________________________*/
void	minilibx_init(t_fdf *fdf, char *win_name);
void	fdf_init(t_fdf *fdf);
void	image_init(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
/*_________________________/controls.c/_________________________*/
int		key_hook(int keycode, t_fdf *fdf);
/*_________________________/ft_split/_________________________*/
char	**ft_split(char const *s, char c);
/*_________________________/draw/_________________________*/
void	draw(t_fdf *fdf);
/*___________________/bresenham.c/__________________*/
void	bresenham(t_fdf *fdf, float x1, float y1);
/*___________________/picasso.c/____________________*/
void	picasso(t_fdf *fdf, t_coordinates *xyz);
/*_________________________/fdf_utils.c/_________________________*/
void	to_free(char **str);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *x, const char *y);
int		ft_atoi(const char *str);
/*_________________________/fdf_utils2.c/_________________________*/
int		ft_max(int a, int b);
int		ft_mod(int a);
char	*ft_strtrim(char const *s1, char const *set);

#endif
