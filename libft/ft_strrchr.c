/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:57:04 by mville            #+#    #+#             */
/*   Updated: 2025/11/12 11:58:42 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = NULL;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			ret = ((char *) &s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		ret = ((char *) &s[i]);
	return (ret);
}
