/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:15:29 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:15:30 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cs;
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		cs = (char*)malloc(sizeof(char) * (i + 1));
		if (cs == 0)
			return (NULL);
		i = 0;
		while (s[i])
		{
			cs[i] = (*f)(s[i]);
			i++;
		}
		cs[i] = '\0';
		return (cs);
	}
	return (NULL);
}
