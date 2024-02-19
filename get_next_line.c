/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:49:34 by boel-bou          #+#    #+#             */
/*   Updated: 2024/02/11 16:49:38 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = malloc(ft_strlen(buffer) - i + 1);
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_buffer(int fd, char *str)
{
	int		i;
	char	*buffer;

	buffer = malloc(10000 + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i != 0 && !(ft_strchr(str, '\n')))
	{
		i = read(fd, buffer, 4);
		if (i == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	write(1, "here_doc> ", 10);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
