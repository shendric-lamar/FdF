/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:15:36 by shendric          #+#    #+#             */
/*   Updated: 2018/12/10 13:36:48 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cs;
	int		i;

	i = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		cs = (char*)malloc(sizeof(char) * (i + 1));
		if (cs == 0)
			return (NULL);
		i = 0;
		while (s[i])
		{
			cs[i] = (*f)(i, s[i]);
			i++;
		}
		cs[i] = '\0';
		return (cs);
	}
	return (NULL);
}
