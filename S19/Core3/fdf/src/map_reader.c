#include "../include/fdf.h"
#include "../include/get_next_line.h"
#include "../include/libft.h"

void process_line(int *row, char *line, int width)
{
    int j = 0;
    char *tok = line;

    while (*tok && j < width)
    {
        while (*tok == ' ' || *tok == '\t')
            tok++;
        if (*tok)
        {
            row[j++] = ft_atoi(tok);
            while (*tok && !(*tok == ' ' || *tok == '\t'))
                tok++;
        }
    }
}

int **map_to_2d_array(t_map map, char *file)
{
    int **matrix;
    int i = 0;
    char *line;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;

    matrix = (int **)malloc(map.height * sizeof(int *));
    if (!matrix)
        return NULL;

    while ((line = get_next_line(fd)))
    {
        matrix[i] = (int *)malloc(map.width * sizeof(int));
        if (!matrix[i])
        {
            free(line);
            close(fd);
            free_matrix(matrix, i);
            return NULL;
        }
        process_line(matrix[i], line, map.width);
        free(line);
        i++;
    }
    close(fd);
    return matrix;
}

int ***map_iso_2d(t_map map, int **matrix, t_map_data data)
{
    int ***n_mat;
    t_coords coords;
    int i = 0, j;

    n_mat = (int ***)malloc(2 * sizeof(int **));
    if (!n_mat)
        return NULL;

    n_mat[0] = (int **)malloc(map.height * sizeof(int *));
    n_mat[1] = (int **)malloc(map.height * sizeof(int *));
    if (!n_mat[0] || !n_mat[1])
    {
        free_iso_matrix(n_mat, map.height);
        return NULL;
    }

    while (i < map.height)
    {
        n_mat[0][i] = (int *)malloc(map.width * sizeof(int));
        n_mat[1][i] = (int *)malloc(map.width * sizeof(int));
        if (!n_mat[0][i] || !n_mat[1][i])
        {
            free_iso_matrix(n_mat, map.height);
            return NULL;
        }

        j = 0;
        while (j < map.width)
        {
            coords.x = i;
            coords.y = j;
            coords.z = matrix[i][j];
            iso_project(coords, &n_mat[0][i][j], &n_mat[1][i][j], data);
            j++;
        }
        i++;
    }

    return n_mat;
}

void find_bounds(int ***iso_matrix, t_map map, t_map_bounds *bounds)
{
    bounds->min_x = bounds->max_x = iso_matrix[0][0][0];
    bounds->min_y = bounds->max_y = iso_matrix[1][0][0];
    int i = 0, j;

    while (i < map.height)
    {
        j = 0;
        while (j < map.width)
        {
            if (iso_matrix[0][i][j] < bounds->min_x)
                bounds->min_x = iso_matrix[0][i][j];
            if (iso_matrix[0][i][j] > bounds->max_x)
                bounds->max_x = iso_matrix[0][i][j];
            if (iso_matrix[1][i][j] < bounds->min_y)
                bounds->min_y = iso_matrix[1][i][j];
            if (iso_matrix[1][i][j] > bounds->max_y)
                bounds->max_y = iso_matrix[1][i][j];
            j++;
        }
        i++;
    }
}