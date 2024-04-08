/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:47:48 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/08 09:37:09 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_read_left_str(int fd, char *left_str);
char	*get_next_line(int fd);
char	*ft_fetch_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);

#endif
