/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:55:42 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:08:19 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	init_cmds(t_pipex *pipex)
{
	int	i;

	pipex->cmds  = (char **)malloc(sizeof(char *) * (pipex->cmd_nb + 1));
	if (pipex->cmds == NULL)
		error_pipe();
	pipex->cmds[pipex->cmd_nb] == NULL;
	i = 0;
	while (i < pipex->cmd_nb)
	{
		pipex->cmds[i] == NULL;
		i++;
	}
}

static void	cmd_builder(t_pipex *pipex, int i)
{
	int	ret;
	int j;

	j = 0;
	while (j < pipex->path_nb)
	{
		pipex->cmds[i] = ft_strappend(pipex->env[j],
								pipex->args[i][0], false, false);
		return = access(pipex->cmds[i], F_OK | X_OK);
		if (ret == 0)
			break ;
		else
		{
			free(pipex->cmds[i]);
			pipex->cmds[i] == NULL;
		}
		j++;
	}
}

void	handle_cmd(t_pipex *pipex)
{
	int	i;

	i = 0;
	init_cmds(pipex);
	while (i < pipex->cmd_nb)
	{
		cmd_builder(pipex, i);
		if (pipex->cmds[i] == NULL)
			error_pipe();
		i++;
	}
}
