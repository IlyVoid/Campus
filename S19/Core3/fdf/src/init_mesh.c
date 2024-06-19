#include "../include/fdf.h"

void    center_mesh(t_FdF *s)
{
    t_vec2  center;
    size_t  i;

    center.x = (double)(s->mesh_width - 1) / 2;
    center.y = (double)(s->mesh_height - 1) / 2;
    i = 0;
    while (i < s->vert_count)
    {
        s->mesh[i].x -= center.x;
        s->mesh[i].y -= center.y;
        i++;
    }
}