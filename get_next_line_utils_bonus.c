/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:13 by hlakhal-          #+#    #+#             */
/*   Updated: 2022/11/15 15:28:48 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
