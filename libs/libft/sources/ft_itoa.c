/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:09:22 by shendric          #+#    #+#             */
/*   Updated: 2018/12/10 12:29:44 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		if (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

static int	ft_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		c;

	c = 0;
	len = ft_len(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (ft_neg(n) == 1)
	{
		str[0] = '-';
		c = 1;
	}
	while (len >= c)
	{
		if (ft_neg(n % 10) == 1)
			str[len--] = -(n % 10) + '0';
		else
			str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
