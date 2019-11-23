/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:17:22 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:17:24 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int		i;
	int		j;
	char	*cstr;
	char	*cfind;

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
			while (cstr[i + j] == cfind[j])
			{
				if (cfind[j + 1] == '\0')
					return (cstr + i);
				j++;
			}
			i++;
		}
	return (0);
}
