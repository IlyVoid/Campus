#include "../include/fdf.h"

// Function to initialize line drawing parameters
void init_params(t_line_params *params)
{
    params->dx = abs(params->x1 - params->x0);
    params->dy = abs(params->y1 - params->y0);
    params->x_direction = (params->x0 < params->x1) ? 1 : -1;
    params->y_direction = (params->y0 < params->y1) ? 1 : -1;
    params->err = params->dx - params->dy;
}

// Function to get the color based on height
int get_color(int height)
{
    if (height > 100)
        return 0xFFFFFF; // White
    else if (height > 50)
        return 0x402400; // Brown
    else if (height > 30)
        return 0x9A5700; // Orange
    else if (height > 10)
        return 0x009A00; // Dark Green
    else if (height > 0)
        return 0x00FF00; // Green
    else
        return 0x0000FF; // Blue
}