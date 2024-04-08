/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:31:05 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/08 09:50:21 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <stdio.h>*/

char	*ft_read_left_str(int fd, char *left_str)
{
	char	*buff;
	int		read_bytes;

	buff - malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(left_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		return (left_str);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_fetch_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

/*
int	main()
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7);
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
