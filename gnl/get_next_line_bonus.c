/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:00:57 by mville            #+#    #+#             */
/*   Updated: 2025/12/03 15:02:37 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_extract_line(char **bag, char *new)
{
	char	*new_bag;
	char	*line;

	new_bag = ft_strdup(new + 1);
	if (!new_bag)
	{
		free(*bag);
		*bag = NULL;
		return (NULL);
	}
	*(new + 1) = '\0';
	line = *bag;
	*bag = new_bag;
	return (line);
}

static char	*ft_cutter(char **bag)
{
	char	*line;
	char	*new;

	new = ft_strchr(*bag, '\n');
	if (new)
		return (ft_extract_line(bag, new));
	line = *bag;
	*bag = NULL;
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static int	ft_helper(char **bag, char *buffer)
{
	char	*tmp;

	tmp = *bag;
	*bag = ft_strjoin(*bag, buffer);
	free(tmp);
	if (!*bag)
		return (0);
	return (1);
}

static char	*get_next_line_core(int fd, char *buffer, char **bag)
{
	int	read_bytes;

	if (!*bag)
	{
		*bag = ft_strdup("");
		if (!*bag)
			return (NULL);
	}
	while (1)
	{
		if (ft_strchr(*bag, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_free_exit(NULL, bag));
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!ft_helper(bag, buffer))
			return (NULL);
	}
	return (ft_cutter(bag));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*bag[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_exit(NULL, &bag[fd]));
	line = get_next_line_core(fd, buffer, &bag[fd]);
	free(buffer);
	return (line);
}
