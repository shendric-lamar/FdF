/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:10:54 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:10:56 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	cc;
	char			*cs;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	cs = (char *)s;
	while (len > i)
	{
		cs[i] = cc;
		i++;
	}
	return ((void *)cs);
}
