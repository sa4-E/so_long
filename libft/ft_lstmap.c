/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:24:05 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/29 22:58:40 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*startnewlst;
	t_list	*newcontent;

	startnewlst = 0;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		newcontent = ft_lstnew(f(lst->content));
		if (!newcontent)
		{
			ft_lstclear(&startnewlst, del);
			return (NULL);
		}
		ft_lstadd_back(&startnewlst, newcontent);
		lst = lst->next;
	}
	return (startnewlst);
}
