/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:36:25 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/23 15:27:17 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*#include <stdio.h>*/

char	*ft_read_left_str(int fd, char *left_str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_fetch_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
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

	// Open the files
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("Error opening file");
		return (1); // Return an error code
	}

	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d] from file 1: %s\n", i, line);
		free(line);

		line = get_next_line(fd2);
		printf("line [%02d] from file 2: %s\n", i, line);
		free(line);

		line = get_next_line(fd3);
		printf("line [%02d] from file 3: %s\n", i, line);
		free(line);

		i++;
	}

	// Close the files
	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
*/
