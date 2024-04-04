/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:47:48 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/04 11:45:11 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifdef GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_new_line_left(char *left_str);
char	*fetch_line(char *left_str);
char	*ft_read_left(int fd, char *str);
char	*ft_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(const char *str);

#endif
