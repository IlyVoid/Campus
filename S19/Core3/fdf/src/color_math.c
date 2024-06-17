#include "../include/fdf.h"

/**
 * Samples a texture at given coordinates.
 *
 * This function retrieves the color of a texture pixel at the specified (x, y) coordinates.
 * It checks bounds and returns the color value as an unsigned integer.
 */

unsigned int    sample_texture(mlx_texture_t *image, int x, int y)
{
    t_color         color;
    unsigned int    pos;

    color.color = 0;
    if (x >= 0 && x < (int)image->width
        && y >= 0 && y < (int)image -> height)
    {
        pos = (x * 4) + (y * image->width * 4);
        color.channel[R] = image->pixels[pos + 0];
        color.channel[G] = image->pixels[pos + 1];
        color.channel[B] = image->pixels[pos + 2];
        color.channel[A] = image->pixels[pos + 3];
    }
    return (color.color);
}

/**
 * Samples a pixel from an image at specified coordinates.
 *
 * This function retrieves the color of a pixel at the given (x, y) coordinates
 * from the provided image. It checks bounds and returns the color value as
 * an unsigned integer.
 */

unsigned int    sample_image(mlx_image_t *image, int x, int y)
{
    t_color         color;
    unsigned int    pos;

    color.color = 0;
    if (x >= 0 && x < (int)image->width
        && y >= 0 && y < (int)image -> height)
    {
        pos = (x * 4) + (y * image->width * 4);
        color.channel[R] = image->pixels[pos + 0];
        color.channel[G] = image->pixels[pos + 1];
        color.channel[B] = image->pixels[pos + 2];
        color.channel[A] = image->pixels[pos + 3];
    }
    return (color.color);
}

/**
 * Linearly interpolates between two color channels.
 *
 * This function performs linear interpolation between two color channels `a` and `b`
 * based on the given `factor`. It calculates the interpolated value and returns it.
 */

unsigned int    lerp_color_channel(unsigned int a, unsigned int b, unsigned int factor)
{
    unsigned int r;

    r = round(a * (1 - factor)) + (b * factor);
    return (r);
}

/**
 * Linearly interpolates between two colors.
 *
 * This function performs linear interpolation between two colors `color_a` and `color_b`
 * based on the given `factor`. It calculates the interpolated color and returns it.
 */

unsigned int    lerp_color(unsigned int color_a, unsigned int color_b, double factor)
{
    t_color a;
    t_color b;
    t_color r;

    factor = fmin(factor, 1);
    factor = fmax(factor, 0);
    a.color = color_a;
    b.color = color_b;
    r.channel[R] = lerp_color_channel(a.channel[R], b.channel[R], factor);
    r.channel[G] = lerp_color_channel(a.channel[G], b.channel[G], factor);
    r.channel[B] = lerp_color_channel(a.channel[B], b.channel[B], factor);
    r.channel[A] = lerp_color_channel(a.channel[A], b.channel[A], factor);
    return (r.color);
}

/**
 * Fades between two colors based on step count and current step.
 *
 * This function fades between two colors `col_a` and `col_b` based on the number of `steps`
 * and the current `step`. It calculates the interpolated color and returns it.
 */

unsigned int    fade_color(unsigned int col_a, unsigned int col_b, int steps, int step)
{
    t_color a;
    t_color b;

    if (steps < 6)
        return (col_a);
    if (steps > 30)
        return (lerp_color(col_a, col_b, (double)step / steps));
    a.color = col_a;
    b.color = col_b;
    a.channel[R] += (b.channel[R] - a.channel[R]) / steps * step;
    a.channel[G] += (b.channel[G] - a.channel[G]) / steps * step;
    a.channel[B] += (b.channel[B] - a.channel[B]) / steps * step;
    a.channel[A] += (b.channel[A] - a.channel[A]) / steps * step;
    return (a.color);
}