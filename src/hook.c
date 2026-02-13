/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:21:24 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 12:24:05 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_management(int keycode, void *param)
{
	if (keycode == 65307)
		exit_hook(param);
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
