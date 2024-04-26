/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:31:05 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/26 17:01:58 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
			free(left_str);
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

	// Open the files
	fd1 = open("tests/no_new_line.txt", O_RDONLY);

	if (fd1 == -1)
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
		i++;
	}

	// Close the files
	close(fd1);

	return (0);

}
*/
