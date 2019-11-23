/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:26:37 by shendric          #+#    #+#             */
/*   Updated: 2018/12/10 12:26:57 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flist;
	t_list	*fresh;

	if (!lst)
		return (NULL);
	flist = (*f)(lst);
	fresh = flist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(flist->next = f(lst)))
		{
			free(flist->next);
			return (NULL);
		}
		flist = flist->next;
	}
	return (fresh);
}
