/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:18:27 by shendric          #+#    #+#             */
/*   Updated: 2018/12/10 14:25:15 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	start;
	char			*a;

	i = 0;
	if (s)
	{
		while (s && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
		start = i;
		len = ft_strlen(s);
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
		if ((a = ft_strsub(s, start, len - i)) == NULL)
			return (NULL);
		i = 0;
		while (s && (i < start - len))
			a[i++] = s[start++];
		a[i] = '\0';
		return (a);
	}
	return (0);
}
