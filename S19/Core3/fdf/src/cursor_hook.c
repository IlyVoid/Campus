#include "../include/fdf.h"

/**
 * Sets rotation angles based on mouse distance.
 *
 * This function adjusts the yaw and pitch angles in the FdF structure `s`
 * based on the mouse movement distances `distance.x` and `distance.y`.
 * It ensures yaw is within the range [0, 2 * PI] and pitch is within [0, PI].
 */

void    set_rotation(t_vec2 distance, t_FdF *s)
{
    s->yaw -= (double)distance.x / 300;
    if (s->yaw > 2 * M_PI)
        s->yaw -= 2 * M_PI;
    if (s->yaw < 0)
        s->yaw += 2 * M_PI;
    s->pitch -= (double)distance.y / 300;
    s->pitch = fmax(fmin(s->pitch, M_PI), 0);
}

/**
 * Mouse cursor event handler.
 *
 * This function handles mouse cursor events, adjusting various parameters in the FdF structure `s`
 * based on mouse button states and cursor movements.
 */

void    cursor_hook(double cursor_x, double cursor_y, void *param)
{
    t_FdF   *s;
    t_vec2  distance;

    s = param;
    s->clicked = 0;

    /* check if any mouse button is pressed */
    if (!mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_LEFT)
        && !mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_MIDDLE)
        && !mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_RIGHT))
        return ;

    /* calc distance from initial mouse position */
    distance.x = cursor_x - s->initial_cursor_pos.x;
    distance.y = cursor_y - s->initial_cursor_pos.y;

    /* handle middle button: adjust height scale */
    if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_MIDDLE))
        s->height_scale -= (double)distance.y / 500;

    /* handle right button: adjust rotation */
    if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_RIGHT))
        set_rotation(distance, s);

    /* handle left button: adjust mesh position */
    if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTONLEFT))
    {
        if (!s->orthographic)
            distance = (t_vec2){distance.x * 3.3333, distance.y * 3.3333};
        s->mesh_pos.x += distance.x;
        s->mesh_pos.y += distance.y;
    }

    /* update initial cursor position in windowed mode or sett mouse position in fullscreen mode */
    if (s->wsl_mode)
        s->initial_cursor_pos = (t_ivec2){cursor_x, cursor_y};
    else
        mlx_set_mouse_pos(s->mlx, s->initial_cursor_pos.x, s->initial_cursor_pos.y);
}