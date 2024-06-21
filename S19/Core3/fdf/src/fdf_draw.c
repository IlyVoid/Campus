#include "../includes/fdf.h"

void draw_background(t_fdf *fdf, int width, int height, int bg_color)
{
    int bg_x = 10;
    int bg_y = 10;

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

void display_controls(t_fdf *fdf)
{
    t_controls controls = {20, 20, 0xFFFFFF, 30};

    // Draw a semi-transparent background for the controls
    draw_background(fdf, 300, 250, 0x000000);

    // Display the controls with some styling
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y, controls.color, "Controls:");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + controls.spacing, controls.color, "Zoom In: +");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 2 * controls.spacing, controls.color, "Zoom Out: -");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 3 * controls.spacing, controls.color, "Depth Increase: W");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 4 * controls.spacing, controls.color, "Depth Decrease: S");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 5 * controls.spacing, controls.color, "Rotate Left: A");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 6 * controls.spacing, controls.color, "Rotate Right: D");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 7 * controls.spacing, controls.color, "Move: Arrow keys");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 8 * controls.spacing, controls.color, "Change Color: C");
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, controls.x, controls.y + 9 * controls.spacing, controls.color, "Exit: ESC");
}

void draw(t_fdf *fdf)
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
