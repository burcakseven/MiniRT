/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buseven <buseven@k1m42s05.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:17:03 by buseven           #+#    #+#             */
/*   Updated: 2022/06/26 19:17:05 by buseven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *buffer)
{
	char	*buff;
	int		rd_byte;

	rd_byte = 1;
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!find_nl_char(buffer) && rd_byte != 0)
	{
		rd_byte = read (fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free (buffer);
			free (buff);
			return (NULL);
		}
		buff[rd_byte] = '\0';
		buffer = strjoin(buffer, buff);
	}
	free (buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = get_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_new_line(buffer);
	buffer = get_new_buffer(buffer);
	return (line);
}
/*
int	main()
{
	int fd = open("deneme.txt",O_RDONLY);
	int	bln;
	bln = 1;
	char *str;
	while (bln)
	{
		str = get_next_line(fd);
		if (str)
		{
			printf("%s",str);
		}
		else
			bln = 0;
	}
}*/
