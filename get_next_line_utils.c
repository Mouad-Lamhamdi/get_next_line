/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:34:46 by molamham          #+#    #+#             */
/*   Updated: 2024/12/12 12:03:01 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (dest != src)
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	size_t	total;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(total + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[total] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	i;

	i = (ft_strlen(s) + 1);
	arr = malloc(i);
	if (!arr)
		return (NULL);
	ft_memcpy(arr, s, i);
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
