/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:14:22 by shendric          #+#    #+#             */
/*   Updated: 2018/12/06 13:14:23 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*cs1;
	char	*cs2;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		cs1 = (char *)s1;
		cs2 = (char *)s2;
		while (cs1[i] || cs2[i])
		{
			if (cs1[i] - cs2[i] != 0)
				return (0);
			i++;
		}
	}
	return (1);
}
