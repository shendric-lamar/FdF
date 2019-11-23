/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spozzi <spozzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:41:06 by spozzi            #+#    #+#             */
/*   Updated: 2019/10/03 19:14:30 by spozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_fdf *f)
{
	int z1;
	int z2;

	z1 = f->map[f->y1 / f->s_u][f->x1 / f->s_u];
	z2 = f->map[f->y2 / f->s_u][f->x2 / f->s_u];
	if (f->color != 0)
	{
		f->color = (z1 != z2) ? f->c1 : f->c2;
		f->color = (z1 > 0 && z1 == z2) ? f->c3 : f->color;
	}
}

void	set_proj(t_fdf *f)
{
	double b1;
	double b2;

	b1 = 0.5;
	b2 = 0.5;
	if (f->proj == 0)
	{
		f->i = f->x1 + f->h * f->map[f->y1 / f->s_u][f->x1 / f->s_u] + f->sft_w;
		f->j = f->y1 - f->h * f->map[f->y1 / f->s_u][f->x1 / f->s_u] + f->sft_h;
		f->k = f->x2 + f->h * f->map[f->y2 / f->s_u][f->x2 / f->s_u] + f->sft_w;
		f->l = f->y2 - f->h * f->map[f->y2 / f->s_u][f->x2 / f->s_u] + f->sft_h;
	}
	if (f->proj == 1)
	{
		f->i = b1 * f->x1 + b2 * f->y1 + f->sft_w;
		f->j = -f->h * f->map[f->y1 / f->s_u][f->x1 / f->s_u] - (b1 * f->x1) / 2
				+ (b2 * f->y1) / 2 + f->sft_h;
		f->k = b1 * f->x2 + b2 * f->y2 + f->sft_w;
		f->l = -f->h * f->map[f->y2 / f->s_u][f->x2 / f->s_u] - (b1 * f->x2) / 2
				+ (b2 * f->y2) / 2 + f->sft_h;
	}
	f->m = ((double)(f->j - f->l)) / ((double)(f->i - f->k));
	f->b = f->j - (f->m * f->i);
}

void	connect_points(t_fdf *f)
{
	if ((f->i - f->k) != 0 && f->m <= 1 && f->m >= -1)
	{
		while (f->i++ <= f->k)
			mlx_pixel_put(f->mlx, f->win, f->ox + f->i - 1,
						f->oy + f->m * f->i - 1 + f->b, f->color);
	}
	else if ((f->m >= 1 || f->m <= -1) && (f->i - f->k) != 0)
	{
		if (f->j > f->l)
			while (f->j > f->l)
				mlx_pixel_put(f->mlx, f->win, f->ox + (f->j - f->b) / f->m,
						f->oy + f->j--, f->color);
		else
		{
			while (f->j <= f->l)
				mlx_pixel_put(f->mlx, f->win, f->ox + (f->j - f->b) / f->m,
						f->oy + f->j++, f->color);
		}
	}
	else if ((f->i - f->k) == 0)
	{
		while (f->j <= f->l)
			mlx_pixel_put(f->mlx, f->win, f->ox + f->i,
					f->oy + f->j++, f->color);
	}
}

void	draw_line(t_fdf *f)
{
	f->flag = 0;
	set_proj(f);
	set_color(f);
	if (f->dots)
		mlx_pixel_put(f->mlx, f->win, f->ox + f->i,
				f->oy + f->m * f->i + f->b, f->color);
	else
		connect_points(f);
}

void	draw_connections(t_fdf *f)
{
	f->y1 = 0;
	while (f->y1 < f->map_h * f->s_u)
	{
		f->x1 = 0;
		while (f->x1 < f->map_w * f->s_u)
		{
			if (f->x1 + f->s_u < f->map_w * f->s_u)
			{
				f->y2 = f->y1;
				f->x2 = f->x1 + f->s_u;
				draw_line(f);
			}
			if (f->y1 + f->s_u < f->map_h * f->s_u)
			{
				f->y2 = f->y1 + f->s_u;
				f->x2 = f->x1;
				draw_line(f);
			}
			f->x1 += f->s_u;
		}
		f->y1 += f->s_u;
	}
	if (f->dots)
		mlx_pixel_put(f->mlx, f->win, f->ox + f->k,
				f->oy + f->m * f->k + f->b, f->color);
}
