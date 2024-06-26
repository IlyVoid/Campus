/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:18:18 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:36:23 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <memory.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		cmd_nb;
	int		pipe_nb;
	int		path_nb;
	int		**pipe;
	int		fd_file1;
	int		fd_file2;
	int		here_doc_pipe[2];
	char	**env;
	char	**args;
	char	**cmds;
	char	*limiter;
	bool	here_doc;
	pid_t	*child;
}			t_pipex;

t_pipex	*malloc_pipe(void);
t_pipex	create_pipex(void);
void	destroy_pipex(t_pipex *pipex);
void	free_pipex(t_pipex *pipex);

/*______________PARSER______________*/
void	create_pipe(t_pipex *pipex);
void	create_child(t_pipex *pipex);
void	handle_cmd(t_pipex *pipex);
void	here_doc_stdin_fill_bonus(t_pipex *pipex);
void	here_doc_cmd_parser_bonus(t_pipex *pipex, int argc,
							   char **argv, char **env);
void	cmd_parser(t_pipex *pipex, int argc, char **argv, char **env);
void	here_doc_open_file_bonus(t_pipex *pipex, char *file2);
void	open_files(t_pipex *pipex, char *file1, char *file2);
void	parsing_bonus(t_pipex *pipex, int argc, char **argv, char **env);
void	parsing_basic(t_pipex *pipex, int argc, char **argv, char **env);
void	parsing(t_pipex *pipex, int argc, char **argv, char **env);

/*______________RUNNER______________*/
void	run_last_cmd(t_pipex *pipex, char **env);
void	run_mid_cmd(t_pipex *pipex, char **env, int i);
void	run_first_cmd(t_pipex *pipex, char **env);
void	run_pipe(t_pipex *pipex, char **env);

/*______________ERROR______________*/
void	error_pipe(void);

/*______________EXTRA______________*/
char	*ft_strappend(const char *s1, const char *s2, int free_s1, int free_s2);
void	ft_error(char *error_msg);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr(char const *s);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(const char *s1, const char *s2, int free_s1, int free_s2);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);

#endif
