/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:17:13 by shendric          #+#    #+#             */
/*   Updated: 2018/12/10 14:43:16 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_string(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = 0;
	while (str[i] && str[i] != c)
		i++;
	dest = (char*)malloc(sizeof(char) * (i - 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_arr_size(char *str, char c)
{
	int	i;
	int arr_size;

	i = 0;
	arr_size = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			arr_size++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (arr_size);
}

static void	*ft_freestr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	int		arr_size;
	char	**dest;

	if (str && c)
	{
		if (((dest = (char **)malloc(sizeof(char *)
							* (ft_arr_size((char *)str, c) + 1)))) == 0)
			return (NULL);
		i = 0;
		arr_size = 0;
		while (str[i])
			if (str[i] != c)
			{
				if ((dest[arr_size++] = ft_string((char *)str + i, c)) == NULL)
					ft_freestr(dest);
				while (str[i] && str[i] != c)
					i++;
			}
			else
				i++;
		dest[arr_size] = 0;
		return (dest);
	}
	return (0);
}
