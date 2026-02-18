/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:33:10 by mville            #+#    #+#             */
/*   Updated: 2026/02/10 13:33:15 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	malloc_fail(void)
{
	ft_putstr_fd("Error: malloc failed\n", 2);
	return (1);
}

void	map_error(int index_err, int erreur)
{
	ft_putstr_fd("Error : line ", 2);
	ft_putnbr_fd(index_err, 2);
	if (erreur < 0)
		ft_putstr_fd(" is too short !\n", 2);
	else
		ft_putstr_fd(" is too long !\n", 2);
}

int	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (1);
	if (ft_strncmp(file + (len - 4), ".fdf", 4) != 0)
		return (1);
	return (0);
}
