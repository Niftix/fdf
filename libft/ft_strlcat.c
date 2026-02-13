/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:43:07 by mville            #+#    #+#             */
/*   Updated: 2025/11/12 14:25:33 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	destlen;

	if ((!dest || !src) && destsize == 0)
		return (0);
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen >= destsize)
		return (destsize + srclen);
	if (srclen < (destsize - destlen))
	{
		ft_memcpy(dest + destlen, src, srclen + 1);
	}
	else
	{
		ft_memcpy(dest + destlen, src, destsize - destlen - 1);
		dest[destsize - 1] = '\0';
	}
	return (destlen + srclen);
}
