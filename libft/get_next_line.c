/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:03:33 by aswedan           #+#    #+#             */
/*   Updated: 2024/12/11 14:03:33 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

#define BUFFER_SIZE 1

char	*set_remainder(char *current_line)
{
	size_t	endpoint;
	char	*new_left_c;

	if (!current_line[0])
		return (NULL);
	endpoint = 0;
	while (current_line[endpoint] != '\n' && current_line[endpoint] != '\0')
		endpoint++;
	if (current_line[endpoint] == '\n')
		endpoint++;
	new_left_c = ft_substr(current_line, endpoint,
			ft_strlen(current_line) - endpoint);
	current_line[endpoint] = '\0';
	return (new_left_c);
}

char	*buff_filler(char *left_c, char *buffer, int fd)
{
	ssize_t	returned_read;
	char	*temp;

	returned_read = 1;
	while (returned_read > 0)
	{
		returned_read = read(fd, buffer, BUFFER_SIZE);
		if (returned_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (returned_read == 0)
			break ;
		if (!left_c)
			left_c = ft_strdup("");
		buffer[returned_read] = '\0';
		temp = left_c;
		left_c = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(left_c, '\n'))
			break ;
	}
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	line = buff_filler(left_c, buffer, fd);
	free(buffer);
	if (!line)
		return (NULL);
	left_c = set_remainder(line);
	return (line);
}
// int main()
// {
// 	char	*line;
// 	int	fd = open("t.txt", O_RDONLY);

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
