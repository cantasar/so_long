/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:12:22 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/11 08:41:58 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst)->next)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		(del)(tmp->content);
		free(tmp);
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
