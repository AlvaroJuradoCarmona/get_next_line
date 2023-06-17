/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:34:45 by ajurado-          #+#    #+#             */
/*   Updated: 2023/02/27 13:34:56 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *stbuffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (stbuffer[i] && stbuffer[i] != '\n')
		i++;
	if (!stbuffer[i])
		return (free(stbuffer), NULL);
	res = ft_calloc(ft_strlen(stbuffer) - i + 1, sizeof(char));
	if (!res)
		return (free(stbuffer), NULL);
	i++;
	j = 0;
	while (stbuffer[i])
		res[j++] = stbuffer[i++];
	free(stbuffer);
	return (res);
}

static char	*line(char *stbuffer)
{
	char	*res;
	int		i;

	i = 0;
	if (!stbuffer[i])
		return (NULL);
	while (stbuffer[i] && stbuffer[i] != '\n')
		i++;
	res = ft_calloc(i + 1 + (stbuffer[i] == '\n'), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (stbuffer[i] && stbuffer[i] != '\n')
	{
		res[i] = stbuffer[i];
		i++;
	}
	if (stbuffer[i] && stbuffer[i] == '\n')
		res[i++] = '\n';
	return (res);
}

static char	*join_clear(char *stbuffer, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(stbuffer, buffer);
	free(stbuffer);
	return (aux);
}	

static char	*read_fd(int fd, char *stbuffer)
{
	char	*buffer;
	int		bytes_read;

	if (!stbuffer)
		stbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(stbuffer), NULL);
	bytes_read = 1;
	while (!(ft_strchr(stbuffer, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stbuffer);
			return (free(buffer), NULL);
		}
		buffer[bytes_read] = 0;
		stbuffer = join_clear(stbuffer, buffer);
	}
	return (free(buffer), stbuffer);
}

char	*get_next_line(int fd)
{
	static char	*stbuffer;
	char		*res;

	if (read(fd, 0, 0) < 0)
	{
		free(stbuffer);
		stbuffer = NULL;
		return (NULL);
	}
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stbuffer = read_fd(fd, stbuffer);
	if (!stbuffer)
		return (NULL);
	res = line(stbuffer);
	stbuffer = next_line(stbuffer);
	return (res);
}
