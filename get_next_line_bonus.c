/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:16:24 by molamham          #+#    #+#             */
/*   Updated: 2024/12/12 17:06:51 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *left_over)
{
	int		i;
	char	*str;

	if (!left_over)
		return (NULL);
	i = 0;
	while (left_over[i] && left_over[i] != '\n')
		i++;
	if (left_over[i] == '\n')
		i++;
	str = malloc (i + 1);
	if (!str)
		return (free(left_over), NULL);
	str = ft_memcpy(str, left_over, i);
	str[i] = '\0';
	return (str);
}

char	*get_left_over(char *left_over)
{
	char	*tmp;
	char	*left;

	if (!left_over)
		return (NULL);
	tmp = ft_strchr(left_over, '\n');
	if (!tmp)
		return (free(left_over), NULL);
	left = ft_strdup(tmp + 1);
	free(left_over);
	return (left);
}

char	*read_from_file(char *left_over, int fd)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = malloc ((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (left_over), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		left_over = ft_strjoin(left_over, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read == 0 && (!left_over || !*left_over))
		return (free(left_over), left_over = NULL);
	return (left_over);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_over[FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(left_over[fd]), NULL);
	if (!left_over[fd])
		left_over[fd] = ft_strdup("");
	if (!ft_strchr(left_over[fd], '\n'))
		left_over[fd] = read_from_file(left_over[fd], fd);
	if (!left_over[fd])
		return (free(left_over[fd]), NULL);
	line = get_line(left_over[fd]);
	left_over[fd] = get_left_over(left_over[fd]);
	return (line);
}
