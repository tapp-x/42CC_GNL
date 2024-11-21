/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:48:46 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/19 19:39:10 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*sta_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sta_str = ft_read_line(fd, sta_str);
	if (!sta_str)
		return (NULL);
	line = ft_cut_line(sta_str);
	sta_str = ft_save_rest(sta_str);
	return (line);
}

char	*ft_read_line(int fd, char *sta_str)
{
	char	*buffer;
	int		size;

	size = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (size > 0 && ft_strchr(sta_str, '\n') == 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		sta_str = ft_strjoin(sta_str, buffer);
	}
	free (buffer);
	return (sta_str);
}

char	*ft_save_rest(char *str)
{
	int		y;
	int		i;
	char	*res;

	i = 0;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	res = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!res)
		return (NULL);
	y = -1;
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		res[++y] = str[i];
		i++;
	}
	free(str);
	return (res);
}

char	*ft_cut_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	if ((i == 0 && str[i] != '\n') || !res)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i] = '\n';
	return (res);
}
