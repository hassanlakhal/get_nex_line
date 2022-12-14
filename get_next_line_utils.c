/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:36:21 by hlakhal-          #+#    #+#             */
/*   Updated: 2022/11/15 15:32:16 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	i = 0;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (0);
	else
	{
		while (src[i])
		{
			new[i] = src[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (len && i < (dstsize - 1))
	{
		dst[i] = src[i];
		if (dst[i] == '\0')
			break ;
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	ft_search(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}
