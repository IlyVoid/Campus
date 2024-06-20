#include "../include/fdf.h"
#include "../include/ft_printf.h"
#include "../include/libft.h"

// Function to check the command line arguments
void check_input(int ac, char *file_name)
{
    // Check if the number of arguments is correct
    if (ac != 2)
    {
        ft_printf("Usage: ./fdf <map file>\n");
        exit(EXIT_FAILURE);
    }

    // Check if the file extension is correct
    if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".fdf", 4) != 0)
    {
        ft_printf("Wrong file extension. Expected '.fdf'\n");
        exit(EXIT_FAILURE);
    }
}

// Function to check the map dimensions
void map_checker(int width, int height)
{
    // Check if the map dimensions are valid
    if (width == 0 || height == 0)
    {
        ft_printf("Failed to load map. Ensure the map file exists and is valid.\n");
        exit(EXIT_FAILURE);
    }
}