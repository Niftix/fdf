/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:25:28 by mville            #+#    #+#             */
/*   Updated: 2026/02/05 14:08:01 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_hexa(char c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'));
}

static int	hexa_convert(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	atoi_hexa(const char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i += 2;
	while (str[i] && is_hexa(str[i]))
	{
		result = result * 16 + hexa_convert(str[i]);
		i++;
	}
	return (result);
}

void	parse_point(t_point *point, char *str)
{
	char	*color;

	point->z = ft_atoi(str);
	color = ft_strchr(str, ',');
	if (color)
		point->color = atoi_hexa(color + 1);
	else
		point->color = -1;
}
