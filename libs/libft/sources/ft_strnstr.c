/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:16:53 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:16:55 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t				i;
	size_t				j;
	char				*cstr;
	char				*cfind;

	i = 0;
	cstr = (char *)str;
	cfind = (char *)find;
	if (*cstr != 0 && *cfind == 0)
		return (cstr);
	else if (*cstr == 0 && *cfind == 0)
		return (cstr);
	else if (*cstr != 0 || (*cstr != 0 && *cfind != 0))
		while (cstr[i])
		{
			j = 0;
			while (cstr[i + j] == cfind[j] && i + j < len)
			{
				if (cfind[j + 1] == '\0')
					return (cstr + i);
				j++;
			}
			i++;
		}
	return (0);
}
