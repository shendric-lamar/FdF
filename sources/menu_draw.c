/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:56:48 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 21:10:32 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_boxes_height(t_fdf *f, int x1, int x2, int color)
{
	int i;
	int j;
	int y1;
	int y2;

	y1 = 71;
	y2 = 89;
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

void	draw_boxes_zoom(t_fdf *f, int x1, int x2, int color)
{
	int i;
	int j;
	int y1;
	int y2;

	y1 = 51;
	y2 = 69;
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

void	colors_draw(t_fdf *f, int x, int y, int color)
{
	int x2;
	int y2;
	int i;
	int j;

	i = y;
	x2 = x + 30;
	y2 = y + 30;
	while (i < y2)
	{
		j = x;
		while (j < x2)
		{
			mlx_pixel_put(f->mlx, f->win, j, i, color);
			j++;
		}
		i++;
	}
}

void	proj_draw(t_fdf *f, int x1, int x2, int color)
{
	int i;
	int j;
	int y1;
	int y2;

	y1 = 330;
	y2 = 391;
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

void	menu_draw(t_fdf *f, int y1, int y2, int color)
{
	int i;
	int j;

	i = y1;
	while (i < y2)
	{
		j = f->menu_x0;
		while (j < f->menu_x1)
		{
			mlx_pixel_put(f->mlx, f->win, j, i, color);
			j++;
		}
		i++;
	}
}
