#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <sys/errno.h>

# define WINDOW_WIDTH   1024
# define WINDOW_HEIGHT  1024

typedef union u_color
{
    unsigned int    color;      // Using unsigned int instead of uint32_t
    unsigned char   channel[4];
}               t_color;

typedef struct s_vec2
{
    double      x;
    double      y;
}               t_vec2;

typedef struct s_ivec2
{
    int     x;  // Using int instead of int32_t
    int     y;
}               t_ivec2;

typedef struct s_vec3
{
    double      x;
    double      y;
    double      z;
}               t_vec3;

typedef struct s_pixel
{
    union
    {
        t_ivec2     pos;
        struct
        {
            int     x;
            int     y;
        };
    };
    double          depth;
    union
    {
        unsigned int    color;      // Using unsigned int instead of uint32_t
        unsigned char   channel[4];
    };
    char            vis;        // Using char instead of int8_t
    double          u;
    double          v;
}                   t_pixel;

typedef struct s_vert
{
    union
    {
        t_vec3      pos;
        struct
        {
            double  x;
            double  y;
            double  z;
        };
    };
    t_pixel         pixel;
    t_vec3          world;
}                   t_vert;

typedef struct s_tri
{
    t_pixel         a;
    t_pixel         b;
    t_pixel         c;
    t_ivec2         bbox[2];
    double          weight_a;
    double          weight_b;
    double          weight_c;
    double          area;
}                   t_tri;

typedef struct s_face
{
    t_vert          a;
    t_vert          b;
    t_vert          c;
    t_vert          d;
}                   t_face;

typedef struct s_skybox
{
    mlx_texture_t   *ft_tex;
    mlx_texture_t   *rt_tex;
    mlx_texture_t   *bk_tex;
    mlx_texture_t   *lf_tex;
    mlx_texture_t   *up_tex;
    mlx_texture_t   *dn_tex;
    t_vert          ft[121];
    t_vert          rt[121];
    t_vert          bk[121];
    t_vert          lf[121];
    t_vert          up[121];
    t_vert          dn[121];
}                   t_skybox;

typedef struct s_FdF
{
    t_vert      *mesh;
    t_vec3      x_dir;
    t_vec3      y_dir;
    t_vec3      z_dir;
    t_skybox    skybox;
    size_t      mesh_height;
    size_t      mesh_width;
    t_vec2      mesh_pos;
    size_t      vert_count;
    int         max_height;
    int         min_height;
    mlx_image_t *depth_map;
    mlx_image_t *background;
    mlx_image_t *canvas;
    mlx_image_t *fps_image;
    mlx_t       *mlx;
    char        anti_aliasing;      // Using char instead of int8_t
    char        draw_fps;           // Using char instead of int8_t
    char        draw_verts;         // Using char instead of int8_t
    char        draw_edges;         // Using char instead of int8_t
    char        draw_dotted_edges;  // Using char instead of int8_t
    char        draw_faces;         // Using char instead of int8_t
    char        draw_faces_edges;   // Using char instead of int8_t
    char        draw_skybox;        // Using char instead of int8_t
    t_ivec2     initial_cursor_pos;
    double      height_scale;
    double      mesh_scale;
    double      initial_mesh_scale;
    double      pitch;
    double      yaw;
    double      vert_size;
    double      dot_size;
    short       dot_density;        // Using short instead of int16_t
    unsigned char line_thickness;   // Using unsigned char instead of uint8_t
    char        orthographic;       // Using char instead of int8_t
    char        skybox_number;      // Using char instead of int8_t
    double      clicked;
    char        mouse_buttons_pressed;  // Using char instead of int8_t
    double      foc;
    double      camera_height;
    char        wsl_mode;           // Using char instead of int8_t
}               t_FdF;

  /*****************/
 /*   cleanup.c   */
/*****************/
void delete_skybox_textures(t_FdF *s);
void clean_exit(char *error_message, t_FdF *s);

  /*****************/
 /*  color_math.c */
/*****************/
unsigned int sample_texture(mlx_texture_t *image, int x, int y);
unsigned int sample_image(mlx_image_t *image, int x, int y);
unsigned int lerp_color(unsigned int color_a, unsigned int color_b, double factor);
unsigned int fade_color(unsigned int col_a, unsigned int col_b, int steps, int step);

  /*****************/
 /* cursor_hook.c */
/*****************/
void cursor_hook(double cursor_x, double cursor_y, void *param);

  /*****************/
 /*   init_fdf.c  */
/*****************/
void init_fdf(char *filepath, t_FdF *s);

  /*****************/
 /*  init_hooks.c */
/*****************/
void init_hooks(t_FdF *s);

  /*****************/
 /*  init_mesh.c  */
/*****************/
void init_mesh(int argc, char **argv, t_FdF *s);

  /*****************/
 /*   init_png.c  */
/*****************/
void init_png(char *file1, char *file2, t_FdF *s);

  /*****************/
 /* init_skybox.c */
/*****************/
void load_skybox_textures(unsigned char sky_number, t_FdF *s);
void init_skybox(t_FdF *s);
void key_hook(mlx_key_data_t keydata, void *param);
void main_loop(void *param);
void project_mesh(t_FdF *s);
void put_dot(mlx_image_t *image, t_pixel pixel, unsigned char size, t_FdF *s);
void put_dotted_line(t_vert a, t_vert b, unsigned char size, t_FdF *s);
void put_face(t_face face, t_FdF *s);
unsigned int line_is_visible(t_pixel a, t_pixel b, t_FdF *s);
void put_line(t_pixel a, t_pixel b, unsigned char thickness, t_FdF *s);
void put_mesh(t_FdF *s);
void put_aa_pixel(mlx_image_t *img, t_pixel pixel, t_FdF *s);
void put_pixel(mlx_image_t *img, t_pixel pixel, unsigned char size, t_FdF *s);
void put_sky_tri(mlx_texture_t *texture, t_tri tri, t_FdF *s);
void put_skybox(t_FdF *s);
void set_vert_colors(t_FdF *s);
void set_min_max_height(t_FdF *s);
void validate_value(char *str, t_FdF *s);
double get_length(t_ivec2 p1, t_ivec2 p2);
double edge_function(t_ivec2 a, t_ivec2 b, t_ivec2 p);

#endif
