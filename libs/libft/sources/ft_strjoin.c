/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:14:58 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:14:59 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*cs1;
	char	*cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	if (s1 && s2)
	{
		join = ft_strnew(ft_strlen(cs1) + ft_strlen(cs2));
		if (!join || !cs1 || !cs2)
			return (NULL);
		join = ft_strcpy(join, cs1);
		join = ft_strcat(join, cs2);
		return (join);
	}
	return (NULL);
}
