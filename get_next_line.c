/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:47:17 by hlakhal-          #+#    #+#             */
/*   Updated: 2022/11/13 04:52:15 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return ft_strdup((char *)s2);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (0);
	while (i < (int)ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < (int)ft_strlen(s2))
	{
		newstr[i++] = s2[j];
		j++;
	}
	newstr[i] = '\0';
	free((char *)s1);
	return (newstr);
}

char *ft_next(char *buffer)
{
	char *str;
	int j;
	int i;
	i =0;
	if (!buffer)
		return NULL;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return NULL;
	}
	str = malloc((ft_strlen(buffer) - i ) * sizeof(char));
	j = 0;
	i++;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return str;
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
	j++;
	new = malloc(j + 1);
	if (!new)
		return (NULL);
	while (i < j)
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char *rempler(int fd, char *temp)
{
	char *str;
	str = malloc((BUFFER_SIZE  + 1)* sizeof(char));
	if (!str)
		return NULL;
	int red;
	size_t i;
	i =0;
     red = 1;
	 while (red)
	 {
		red = read(fd,str,BUFFER_SIZE);
		if (red == -1)
		{
			free(str);
			free(temp);
			return NULL;
		}
		 if (!red)
			break;
		str[red] = '\0';
		temp = ft_strjoin(temp,str);
		if (ft_strchr(str,'\n'))
			break;
	 }
	 free(str);
	 return temp;
}
char *get_next_line(int fd)
{
	char *buffer ;
	static char *temp;
	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	temp = rempler(fd,temp);
	buffer = ret_line(temp);
	temp = ft_next(temp);
	return buffer;
}
