/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:46:20 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 22:04:14 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int i)
{
	if (i == 1)
	{
		ft_putendl("error");
		exit(1);
	}
	if (i == 2)
		ft_putendl("error! usage: ./fdf map_folder/map_name");
}

void	str_replace(char *str, t_fdf *f)
{
	int i;

	i = 0;
	while (i < f->size)
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
}

void	str_to_int(char **map, t_fdf *f)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < f->map_h)
	{
		if (!(f->map[i] = (int *)malloc(sizeof(int) * f->map_w)))
			ft_error(1);
		j = 0;
		while (j < f->map_w)
		{
			f->map[i][j] = ft_atoi(map[k]);
			j++;
			k++;
		}
		i++;
	}
}
