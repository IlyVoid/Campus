/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:48:19 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/21 02:11:42 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_left_str(int fd, char *left_str);
char	*ft_str_chr(char *s, int c);
size_t	str_len(char *s);
char	*ft_str_join(char *left_str, char *buff);
char	*ft_fetch_line(char *left_str);
char	*ft_new_left_str(char *left_str);

#endif
