/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguitar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:43:01 by auguitar          #+#    #+#             */
/*   Updated: 2018/11/28 17:17:34 by auguitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			len;
	unsigned char	*y;

	y = (unsigned char *)src;
	i = 0;
	while (dst[i])
		i++;
	len = 0;
	j = 0;
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dst[i + j] = y[j];
		len++;
		j++;
	}
	dst[i + j] = '\0';
	while (y[len])
		len++;
	if (size < i)
		return (len + size);
	return (len + i);
}
