/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:35:47 by mville            #+#    #+#             */
/*   Updated: 2026/01/30 14:35:50 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	win_size(t_fdf *fdf)
{
	fdf->win.win_width = fdf->map.width * 10;
	fdf->win.win_height = fdf->map.height * 10;
	if (fdf->win.win_width > 1920)
		fdf->win.win_width = 1920;
	if (fdf->win.win_height > 1080)
		fdf->win.win_height = 1080;
	if (fdf->win.win_width < 800)
		fdf->win.win_width = 800;
	if (fdf->win.win_height < 600)
		fdf->win.win_height = 600;
}

void	fdf_init(t_fdf *fdf)
{
	int	zoom_x;
	int	zoom_y;

	win_size(fdf);
	zoom_x = fdf->win.win_width / fdf->map.width;
	zoom_y = fdf->win.win_height / fdf->map.height;
	if (zoom_x < zoom_y)
		fdf->zoom = zoom_x / 2;
	else
		fdf->zoom = zoom_y / 2;
	if (fdf->zoom < 3)
		fdf->zoom = 3;
	fdf->shift_x = fdf->win.win_width / 2;
	fdf->shift_y = fdf->win.win_height / 4;
	fdf->color = 0xFFFFFF;
	fdf->z_management = 1.0;
	fdf->rot_x = 0.0;
	fdf->rot_y = 0.0;
	fdf->rot_z = 0.0;
	fdf->iso = 1;
	fdf->angle = 0.523599;
}

int	graphic_init(t_fdf *fdf)
{
	fdf_init(fdf);
	fdf->mlx.mlx = mlx_init();
	if (!fdf->mlx.mlx)
		return (1);
	fdf->mlx.mlx_win = mlx_new_window(fdf->mlx.mlx,
			fdf->win.win_width, fdf->win.win_height, "FDF - MVILLE");
	if (!fdf->mlx.mlx_win)
	{
		mlx_destroy_display(fdf->mlx.mlx);
		free(fdf->mlx.mlx);
		return (1);
	}
	fdf->mlx.img.img = mlx_new_image(fdf->mlx.mlx,
			fdf->win.win_width, fdf->win.win_height);
	if (!fdf->mlx.img.img)
	{
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.mlx_win);
		mlx_destroy_display(fdf->mlx.mlx);
		free(fdf->mlx.mlx);
		return (1);
	}
	fdf->mlx.img.addr = mlx_get_data_addr(fdf->mlx.img.img,
			&fdf->mlx.img.bits_per_pixel,
			&fdf->mlx.img.line_length, &fdf->mlx.img.endian);
	return (0);
}
