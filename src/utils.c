/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:09:03 by mville            #+#    #+#             */
/*   Updated: 2026/01/20 17:09:05 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_word(char *str, char sep)
{
	int	count;

	count = 0;
	while (*str && *str != '\n')
	{
		while (*str && *str != '\n' && sep == *str)
			str++;
		if (*str && *str != '\n' && sep != *str)
			count++;
		while (*str && *str != '\n' && sep != *str)
			str++;
	}
	return (count);
}

void	*ft_final_free(t_fdf *fdf)
{
	free(fdf->map.tab);
	mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img.img);
	mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.mlx_win);
	mlx_destroy_display(fdf->mlx.mlx);
	free(fdf->mlx.mlx);
	return (NULL);
}

void	*ft_free(t_point *tab)
{
	free(tab);
	return (NULL);
}

void	clean_fd_line(t_fdf *fdf)
{
	char	*line;

	free(fdf->file.line);
	line = get_next_line(fdf->file.fd);
	while (line)
	{
		free(line);
		line = get_next_line(fdf->file.fd);
	}
	close(fdf->file.fd);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
