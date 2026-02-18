/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:07:32 by mville            #+#    #+#             */
/*   Updated: 2026/01/20 17:07:41 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2 || check_file(av[1]))
	{
		ft_putstr_fd("Error : Run the program with ./fdf file.fdf\n", 2);
		ft_putstr_fd("Only .fdf files are accepted\n", 2);
		return (2);
	}
	if (parsing_core((av[1]), &fdf))
		return (3);
	if (graphic_init(&fdf))
	{
		ft_free(fdf.map.tab);
		return (4);
	}
	fdf.needs_redraw = 0;
	draw_image(&fdf);
	mlx_put_image_to_window(fdf.mlx.mlx, fdf.mlx.mlx_win,
		fdf.mlx.img.img, 0, 0);
	mlx_hook(fdf.mlx.mlx_win, 2, 1L << 0, key_management, &fdf);
	mlx_hook(fdf.mlx.mlx_win, 17, 0, exit_hook, &fdf);
	mlx_expose_hook(fdf.mlx.mlx_win, expose_hook, &fdf);
	mlx_loop_hook(fdf.mlx.mlx, render_loop, &fdf);
	mlx_loop(fdf.mlx.mlx);
	return (0);
}
