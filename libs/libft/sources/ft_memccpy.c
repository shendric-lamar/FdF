/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:09:47 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:09:48 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	cc = (unsigned char)c;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (n > i && (i == 0 || csrc[i - 1] != cc))
	{
		cdst[i] = csrc[i];
		i++;
	}
	if (i > 0 && csrc[i - 1] == cc)
		return (cdst + i);
	else
		return (0);
}
