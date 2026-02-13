/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:33:50 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 14:08:24 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *fdf, int *x, int *y, int *z)
{
	int	tmp;

	tmp = *y;
	*y = tmp * cos(fdf->rot_x) - *z * sin(fdf->rot_x);
	*z = tmp * sin(fdf->rot_x) + *z * cos(fdf->rot_x);
	tmp = *x;
	*x = tmp * cos(fdf->rot_y) + *z * sin(fdf->rot_y);
	*z = -tmp * sin(fdf->rot_y) + *z * cos(fdf->rot_y);
	tmp = *x;
	*x = tmp * cos(fdf->rot_z) - *y * sin(fdf->rot_z);
	*y = tmp * sin(fdf->rot_z) + *y * cos(fdf->rot_z);
}
