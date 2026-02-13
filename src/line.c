/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:04:12 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 12:24:51 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso_view(t_fdf *fdf, int *x, int *y, int z)
{
	int	old_x;
	int	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(fdf->angle);
	*y = (old_x + old_y) * sin(fdf->angle) - z;
}

static void	next_point_x(t_point *p2, t_fdf *fdf, int x, int y)
{
		p2->x = (x + 1) * fdf->zoom;
		p2->y = y * fdf->zoom;
		p2->z = fdf->map.tab[y][x + 1].z * (fdf->zoom / 2) * fdf->z_management;
}

static void	next_point_y(t_point *p2, t_fdf *fdf, int x, int y)
{
		p2->x = x * fdf->zoom;
		p2->y = (y + 1) * fdf->zoom;
		p2->z = fdf->map.tab[y + 1][x].z * (fdf->zoom / 2) * fdf->z_management;
}

static void	line_init(t_fdf *fdf, int x, int y, int is_right)
{
	t_point	p1;
	t_point	p2;

	p1.x = x * fdf->zoom;
	p1.y = y * fdf->zoom;
	p1.z = fdf->map.tab[y][x].z * (fdf->zoom / 2) * fdf->z_management;
	p1.color = fdf->map.tab[y][x].color;
	p2.color = fdf->map.tab[y][x].color;
	if (is_right)
		next_point_x(&p2, fdf, x, y);
	else
		next_point_y(&p2, fdf, x, y);
	rotate(fdf, &p1.x, &p1.y, &p1.z);
	rotate(fdf, &p2.x, &p2.y, &p2.z);
	if (fdf->iso)
	{
		iso_view(fdf, &p1.x, &p1.y, p1.z);
		iso_view(fdf, &p2.x, &p2.y, p2.z);
	}
	p1.x += fdf->shift_x;
	p1.y += fdf->shift_y;
	p2.x += fdf->shift_x;
	p2.y += fdf->shift_y;
	bresenham_start(fdf, p1, p2);
}

void	draw_image(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				line_init(fdf, x, y, 1);
			if (y < fdf->map.height - 1)
				line_init(fdf, x, y, 0);
			x++;
		}
		y++;
	}
}
