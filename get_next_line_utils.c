/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:35:23 by ajurado-          #+#    #+#             */
/*   Updated: 2023/02/27 13:35:26 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	char	*aux;

	if (!str)
		return (0);
	aux = (char *)str;
	while (*aux)
	{
		if (*aux == (unsigned char) c)
			return ((char *) aux);
		aux++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	concat = malloc(sizeof(char) * (len + 1));
	if (!concat || !s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		concat[i++] = s2[j++];
	concat[len] = '\0';
	return (concat);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*arr;
	size_t	i;

	arr = malloc(nitems * size);
	if (!arr)
		return (0);
	i = -1;
	while (++i < nitems * size)
		((char *) arr)[i] = '\0';
	return (arr);
}
