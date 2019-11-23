/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:34:04 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 22:15:51 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_fdf *f)
{
	free(f->mlx);
	free(f->win);
	f->i = -1;
	while (++f->i < f->map_h)
		free(f->map[f->i]);
	free(f->map);
}

void	map_dimensions(int fd, t_fdf *f)
{
	char	buf[BUF_SIZE];
	char	*tab;
	char	**map;

	f->i = -1;
	if (!(f->size = read(fd, buf, BUF_SIZE)))
		ft_error(1);
	buf[f->size] = '\0';
	tab = ft_strdup(buf);
	map = ft_strsplit(tab, '\n');
	while (map[++f->i] != '\0')
	{
		f->j = -1;
		while (map[f->i][++f->j] != '\0')
			if ((ft_isdigit(map[f->i][f->j]) == 1) && (f->map_h == 0)
				&& (ft_isdigit(map[f->i][f->j + 1]) != 1))
				f->map_w++;
		f->map_h++;
	}
	free(tab);
	f->i = -1;
	while (map[++f->i])
		free(map[f->i]);
	free(map);
}

void	proj_draw_dots(t_fdf *f, int x1, int x2, int color)
{
	int i;
	int j;
	int y1;
	int y2;

	y1 = 395;
	y2 = 456;
	i = y1;
	while (i < y2)
	{
		j = x1;
		while (j < x2)
		{
			mlx_pixel_put(f->mlx, f->win, j, i, color);
			j++;
		}
		i++;
	}
}

void	dots(t_fdf *f)
{
	f->color = 0;
	draw_connections(f);
	if (f->flag2 == 0)
	{
		f->dots = 1;
		f->flag2 = 1;
	}
	else if (f->flag2 == 1)
	{
		f->dots = 0;
		f->flag2 = 0;
	}
	f->color = MENU_SQ;
	draw_connections(f);
	menu(f);
}
