/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:03:59 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 12:39:25 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= fdf->win.win_width || y < 0
		|| y >= fdf->win.win_height)
		return ;
	dst = fdf->mlx.img.addr + (y * fdf->mlx.img.line_length + x
			* (fdf->mlx.img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	bresenham_solv(t_bresenham *infos, t_fdf *fdf, int color)
{
	int	e2;

	while (infos->x != infos->x1 || infos->y != infos->y1)
	{
		my_mlx_pixel_put(fdf, infos->x, infos->y, color);
		e2 = 2 * infos->error;
		if (e2 > -infos->dy)
		{
			infos->error -= infos->dy;
			infos->x += infos->pas_x;
		}
		if (e2 < infos->dx)
		{
			infos->error += infos->dx;
			infos->y += infos->pas_y;
		}
	}
	my_mlx_pixel_put(fdf, infos->x, infos->y, color);
}

static void	bresenham_init(t_bresenham *infos, t_point start, t_point end)
{
	infos->x = start.x;
	infos->y = start.y;
	infos->x1 = end.x;
	infos->y1 = end.y;
	infos->dx = ft_abs(infos->x1 - infos->x);
	infos->dy = ft_abs(infos->y1 - infos->y);
	infos->error = infos->dx - infos->dy;
	if (infos->x1 > infos->x)
		infos->pas_x = 1;
	else
		infos->pas_x = -1;
	if (infos->y1 > infos->y)
		infos->pas_y = 1;
	else
		infos->pas_y = -1;
}

static int	check_offscreen(t_fdf *fdf, t_point start, t_point end)
{
	if (start.x < 0 && end.x < 0)
		return (1);
	if (start.y < 0 && end.y < 0)
		return (1);
	if (start.x >= fdf->win.win_width && end.x >= fdf->win.win_width)
		return (1);
	if (start.y >= fdf->win.win_height && end.y >= fdf->win.win_height)
		return (1);
	return (0);
}

void	bresenham_start(t_fdf *fdf, t_point start, t_point end)
{
	t_bresenham	infos;
	int			color;

	if (check_offscreen(fdf, start, end))
		return ;
	if (start.color == -1)
		color = fdf->color;
	else
		color = start.color;
	bresenham_init(&infos, start, end);
	bresenham_solv(&infos, fdf, color);
}
