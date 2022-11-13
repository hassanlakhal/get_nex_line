/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:36:21 by hlakhal-          #+#    #+#             */
/*   Updated: 2022/11/13 00:35:57 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		len;
	int		i;

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

char	*ft_strchr(const char *s, int c)
{
	while (s[0] != (char)c)
	{
		if (s[0] == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}
