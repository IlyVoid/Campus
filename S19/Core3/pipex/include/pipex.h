/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:18:18 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/04 13:43:08 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft.h"

/* Mandatory functions */
void	error(void);
char	*find_path(char *cmd, char **env);
int		get_next_line(char **line);
void	execute(char *argv, char **env);

/* Bonus functions */
int		open_file(char *argv, int i);
void	usage(void);

#endif
