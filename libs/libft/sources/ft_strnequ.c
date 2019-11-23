/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:16:24 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:16:26 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char			*a;
	char			*b;
	size_t			i;

	a = (char *)s1;
	b = (char *)s2;
	i = 0;
	if (s1 && s2)
	{
		while (a[i] && (a[i] == b[i]) && (i < n))
			i++;
		if (a[i] != b[i] && (i < n))
			return (0);
		else
			return (1);
	}
	return (0);
}
