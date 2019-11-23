/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:10:45 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:10:47 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	i = 0;
	if (cdst > csrc)
		while (len--)
			cdst[len] = csrc[len];
	else
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	return (cdst);
}
