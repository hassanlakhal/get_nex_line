/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 02:20:47 by hlakhal-          #+#    #+#             */
/*   Updated: 2022/11/15 15:29:02 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup((char *)s2));
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i++] = s2[j];
		j++;
	}
	newstr[i] = '\0';
	free((char *)s1);
	return (newstr);
}

char	*ft_next(char *buffer)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(buffer) - i) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*ret_line(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		j++;
	new = malloc(j + 1);
	if (!new)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*ft_read(int fd, char *temp)
{
	char	*str;
	int		red;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (ft_search(str, '\n'))
	{
		red = read(fd, str, BUFFER_SIZE);
		if (red == -1)
		{
			free(str);
			if (temp)
				free(temp);
			return (NULL);
		}
		if (!red)
			break ;
		str[red] = '\0';
		temp = ft_strjoin(temp, str);
	}
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = ft_read(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	buffer = ret_line(temp[fd]);
	temp[fd] = ft_next(temp[fd]);
	return (buffer);
}
