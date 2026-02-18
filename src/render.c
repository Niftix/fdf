/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:25:39 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 12:27:11 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw(t_fdf *fdf)
{
	ft_bzero(fdf->mlx.img.addr, fdf->mlx.img.line_length * fdf->win.win_height);
	draw_image(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.mlx_win,
		fdf->mlx.img.img, 0, 0);
}

int	render_loop(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->needs_redraw)
	{
		redraw(fdf);
		fdf->needs_redraw = 0;
	}
	return (0);
}
