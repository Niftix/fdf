/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mville <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:25:31 by mville            #+#    #+#             */
/*   Updated: 2025/11/13 13:26:51 by mville           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*atm;
	t_list	*next;

	if (!lst || !del)
		return ;
	atm = *lst;
	while (atm)
	{
		next = atm->next;
		del(atm->content);
		free(atm);
		atm = next;
	}
	*lst = NULL;
}
