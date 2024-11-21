/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:50:25 by tappourc          #+#    #+#             */
/*   Updated: 2023/11/18 11:53:41 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		lenght;
	int		i;
	int		y;
	char	*dest;

	i = -1;
	y = -1;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	lenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc((lenght + 2) * (sizeof(char)));
	if (!dest)
		return (NULL);
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	while (s2[++y] != '\0')
		dest[i + y] = s2[y];
	dest[i + y] = '\0';
	free (s1);
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	if (!s)
		return (0);
	while (s[i] != '\0' && (s[i] != c % 128))
		i++;
	if (s[i] == c % 128)
	{
		str += i;
		return (str);
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(int nmemb, int size)
{
	int				i;
	int				y;
	unsigned char	*ptr;

	i = nmemb * size;
	if ((int)i < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(i);
	if (nmemb == 0)
		return (ptr);
	if (!ptr)
		return (ptr);
	y = 0;
	while (y < i)
	{
		ptr[y] = '\0';
		y++;
	}
	return (ptr);
}
