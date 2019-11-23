/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:17:02 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:17:03 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*max;

	max = 0;
	while (*s)
	{
		if (*s == (char)c)
			max = (char *)s;
		s++;
	}
	if (*s == (char)c)
	{
		max = (char *)s;
	}
	return (max);
}
