/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:08:02 by mville            #+#    #+#             */
/*   Updated: 2026/01/30 14:36:33 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_fill(int y, int x, t_fdf *fdf)
{
	char	**res;

	while (fdf->file.line)
	{
		res = ft_split(fdf->file.line, ' ');
		if (!res)
		{
			clean_fd_line(fdf);
			return (malloc_fail());
		}
		while (res[x] && x < fdf->map.width && y < fdf->map.height)
		{
			parse_point(&fdf->map.tab[y * fdf->map.width + x], res[x]);
			free(res[x++]);
		}
		while (res[x])
			free(res[x++]);
		free(res);
		free(fdf->file.line);
		y++;
		x = 0;
		fdf->file.line = get_next_line(fdf->file.fd);
	}
	close(fdf->file.fd);
	return (0);
}

static int	map_create(t_fdf *fdf)
{
	fdf->map.tab = malloc(sizeof(t_point) * fdf->map.width * fdf->map.height);
	if (!fdf->map.tab)
		return (malloc_fail());
	return (0);
}

static int	read_map_dimensions(t_fdf *fdf)
{
	int		current;
	int		index_err;

	index_err = 1;
	while (fdf->file.line)
	{
		current = count_word(fdf->file.line, ' ');
		if (current != 0 && fdf->map.width != 0 && current != fdf->map.width)
		{
			map_error(index_err, current - fdf->map.width);
			clean_fd_line(fdf);
			return (1);
		}
		if (current != 0 && fdf->map.width == 0)
			fdf->map.width = current;
		if (current != 0)
			fdf->map.height++;
		free(fdf->file.line);
		fdf->file.line = get_next_line(fdf->file.fd);
		index_err++;
	}
	clean_fd_line(fdf);
	return (0);
}

static char	*file_init(char *file, t_fdf *fdf)
{
	fdf->file.fd = open(file, O_RDONLY);
	if (fdf->file.fd == -1)
		return (NULL);
	fdf->file.line = get_next_line(fdf->file.fd);
	if (!fdf->file.line)
	{
		close(fdf->file.fd);
		return (NULL);
	}
	return (fdf->file.line);
}

int	parsing_core(char *file, t_fdf *fdf)
{
	fdf->file.line = file_init(file, fdf);
	if (!fdf->file.line)
	{
		ft_putstr_fd("Error: Could not open file\n", 2);
		return (1);
	}
	fdf->map.width = 0;
	fdf->map.height = 0;
	if (read_map_dimensions(fdf))
		return (1);
	if (map_create(fdf))
		return (1);
	fdf->file.line = file_init(file, fdf);
	if (!fdf->file.line)
	{
		ft_free(fdf->map.tab);
		return (1);
	}
	if (map_fill(0, 0, fdf))
	{
		ft_free(fdf->map.tab);
		return (1);
	}
	return (0);
}
