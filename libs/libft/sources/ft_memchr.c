/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:09:59 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:37:50 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*cs;
	char			cc;

	cs = (char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (cs[i] == cc)
			return (cs + i);
		i++;
	}
	return (NULL);
}
