/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:17:35 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:17:36 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*b;

	i = 0;
	if (s)
	{
		if ((b = ((char *)malloc(sizeof(char) * len + 1))) == 0)
			return (NULL);
		while (i < len && b)
		{
			b[i] = s[start];
			i++;
			start++;
		}
		b[i] = '\0';
		return (b);
	}
	return (0);
}
