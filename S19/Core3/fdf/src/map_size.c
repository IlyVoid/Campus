#include "../include/fdf.h"
#include "../include/get_next_line.h"
#include "../include/libft.h"

t_map init_map_struct(void)
{
    t_map map;
    map.width = 0;
    map.height = 0;
    return map;
}

int open_map(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return 0;
    return fd;
}

void free_values(char **values)
{
    int i = 0;
    while (values[i])
        free(values[i++]);
    free(values);
}

t_map get_sizes(char *file)
{
    t_map map = init_map_struct();
    int fd = open_map(file);
    char *line;
    char **values;

    while (fd != 0)
    {
        line = get_next_line(fd);
        if (!line)
            break;

        map.height++;

        if (map.width == 0)
        {
            values = ft_split(line, ' ');
            while (values[map.width])
                map.width++;
            free_values(values);
        }

        free(line);
    }

    close(fd);
    return map;
}