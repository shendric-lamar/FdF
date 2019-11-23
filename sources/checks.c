/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:34:04 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 19:14:13 by spozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_dimensions(int fd, t_fdf *f)
{
	char	buf[BUFF_SIZE];
	char	*tab;
	char	**map;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(f->size = read(fd, buf, BUFF_SIZE)))
		ft_error(1);
	buf[f->size] = '\0';
	tab = ft_strdup(buf);
	map = ft_strsplit(tab, '\n');
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((ft_isdigit(map[i][j]) == 1) && (f->map_h == 0)
				&& (ft_isdigit(map[i][j + 1]) != 1))
				f->map_w++;
			j++;
		}
		i++;
		f->map_h++;
	}
}
