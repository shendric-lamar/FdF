/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:16:42 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:16:43 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t			i;
	char			*a;

	a = (char *)malloc(sizeof(char) * size + 1);
	if (!a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		a[i] = '\0';
		i++;
	}
	a[i] = '\0';
	return (a);
}
