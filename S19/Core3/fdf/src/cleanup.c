#include "../include/fdf.h"

/**
 * Deletes skybox textures in the FdF application.
 *
 * This function iterates through each skybox texture stored in the given FdF structure
 * and deletes them to free up memory. It sets each texture pointer to NULL after deletion.
 */

void    delete_skybox_textures(t_FdF *s)
{
    if (s->skybox.bk_tex)
        mlx_delete_texture(s->skybox.bk_tex);
    s->skybox.bk_tex = NULL;
    if (s->skybox.dn_tex)
        mlx_delete_texture(s->skybox.dn_tex);
    s->skybox.dn_tex = NULL;
    if (s->skybox.ft_tex)
        mlx_delete_texture(s->skybox.ft_tex);
    s->skybox.ft_tex = NULL;
    if (s->skybox.lf_tex)
        mlx_delete_texture(s->skybox.lf_tex);
    s->skybox.lf_tex = NULL;
    if (s->skybox.rt_tex)
        mlx_delete_texture(s->skybox.rt_tex);
    s->skybox.rt_tex = NULL;
    if (s->skybox.up_tex)
        mlx_delete_texture(s->skybox.up_tex);
    s->skybox.up_tex = NULL;
}

/**
 * Cleans up resources and exits the FdF application.
 *
 * This function performs cleanup operations such as deleting skybox textures,
 * terminating the mlx instance, freeing mesh memory, and printing error messages.
 * It then exits the program with an error status.
 */

void	clean_exit(char *error_message, t_FdF *s)
{
    delete_skybox_textures(s);
    if (s->mlx)
        mlx_terminate(s->mlx);
    if (s->mesh)
        free(s->mesh);
    if (errno)
        perror(error_message);
    else
    {
        ft_putstr_fd(error_message, 2);
        ft_putstr_fd("\n", 2);
    }
    exit (1);
}