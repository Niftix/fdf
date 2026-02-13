/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:13:58 by mville            #+#    #+#             */
/*   Updated: 2025/11/12 11:15:46 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*p;
	size_t				i;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		p[i++] = (unsigned char)c;
	}
	return (b);
}
