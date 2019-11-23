/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:09:34 by shendric          #+#    #+#             */
/*   Updated: 2018/12/10 13:27:24 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if ((s = (void *)malloc(sizeof(void *) * size)) == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
