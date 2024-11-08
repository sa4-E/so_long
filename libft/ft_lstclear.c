/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:28:23 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/29 20:59:19 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*nexttemp;

	temp = *lst;
	while (temp)
	{
		nexttemp = temp->next;
		ft_lstdelone(temp, del);
		temp = nexttemp;
	}
	*lst = NULL;
}
