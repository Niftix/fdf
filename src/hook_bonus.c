/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:21:24 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 12:24:05 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotation_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 113)
		fdf->rot_x += 0.1;
	else if (keycode == 119)
		fdf->rot_x -= 0.1;
	else if (keycode == 97)
		fdf->rot_y += 0.1;
	else if (keycode == 115)
		fdf->rot_y -= 0.1;
	else if (keycode == 122)
		fdf->rot_z += 0.1;
	else if (keycode == 120)
		fdf->rot_z -= 0.1;
}

static void	movement_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 61 && fdf->zoom < 50)
		fdf->zoom += 10;
	else if (keycode == 45 && fdf->zoom > 10)
		fdf->zoom -= 10;
	else if (keycode == 65361)
		fdf->shift_x -= 20;
	else if (keycode == 65363)
		fdf->shift_x += 20;
	else if (keycode == 65362)
		fdf->shift_y -= 20;
	else if (keycode == 65364)
		fdf->shift_y += 20;
	else if (keycode == 99 && fdf->z_management < 10.0)
		fdf->z_management += 0.1;
	else if (keycode == 118 && fdf->z_management > 0.1)
		fdf->z_management -= 0.1;
}

int	key_management(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 65307)
		exit_hook(param);
	if (keycode == 113 || keycode == 119 || keycode == 97
		|| keycode == 115 || keycode == 122 || keycode == 120)
		rotation_hook(keycode, fdf);
	else if (keycode == 61 || keycode == 45
		|| keycode == 65361 || keycode == 65363 || keycode == 65362
		|| keycode == 65364 || keycode == 99 || keycode == 118)
		movement_hook(keycode, fdf);
	else if (keycode == 112)
	{
		if (!fdf->iso)
			fdf->iso = 1;
		else
			fdf->iso = 0;
	}
	else if (keycode == 114)
		fdf_init(fdf);
	else
		return (0);
	fdf->needs_redraw = 1;
	return (0);
}

int	exit_hook(void *param)
{
	ft_final_free(param);
	exit(0);
}

int	expose_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.mlx_win,
		fdf->mlx.img.img, 0, 0);
	return (0);
}
