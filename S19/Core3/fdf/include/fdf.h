#ifndef FDF_H
# define FDF_H

/******************/
/*    Includes    */
/******************/

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/******************/
/*   Structures   */
/******************/

typedef struct s_map
{
    int		width;
    int		height;
}			t_map;

typedef struct s_line_params
{
    int		x0;
    int		y0;
    int		x1;
    int		y1;
    int		dx;
    int		dy;
    int		x_direction;
    int		y_direction;
    int		err;
}			t_line_params;

typedef struct s_data
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}			t_data;

typedef struct s_mlx
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_data	img_data;
}			t_mlx;

typedef struct s_map_data
{
    int		tile_size;
    int		offset_x;
    int		offset_y;
    float	height_scale;
    t_map	*map_ptr;
}			t_map_data;

typedef struct s_map_bounds
{
    int		min_x;
    int		max_x;
    int		min_y;
    int		max_y;
}			t_map_bounds;

typedef struct s_coords
{
    int		x;
    int		y;
    int		z;
}			t_coords;

typedef struct matrix_arr
{
    int		**matrix;
    int		***iso_matrix;
}			t_matrix_arr;

/******************/
/*   Functions    */
/******************/

t_map       get_sizes(char *file);
void        iso_project(t_coords coords, int *screen_x, int *screen_y, t_map_data data);
int         ***map_iso_2d(t_map map, int **matrix, t_map_data data);
void        init_params(t_line_params *params);
void        my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_mlx       setup_mlx(void);
int         get_color(int height);
void        draw_map(int ***iso_matrix, int **matrix, t_mlx *mlx_win, t_map_data data);
int         **map_to_2d_array(t_map map, char *file);
int         key_press(int keycode, t_mlx *mlx_win);
int         close_event(t_mlx *mlx_win);
void        check_input(int ac, char *file_name);
void        map_checker(int width, int height);
int         min(int a, int b);
t_map_data  calc_tile_size(t_map map, int **matrix);
t_map_data  calc_offsets(t_map map, t_map_data data, t_map_bounds bounds);
void        find_bounds(int ***iso_matrix, t_map map, t_map_bounds *bounds);
void        free_matrix(int **matrix, int rows);
void        free_iso_matrix(int ***iso_matrix, int rows);

#endif