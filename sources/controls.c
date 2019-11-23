/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:43:35 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 19:14:31 by spozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height(t_fdf *f, int key)
{
	f->color = 0;
	draw_connections(f);
	if (key == H)
		f->h += 2;
	else if (key == L)
		f->h -= 2;
	f->color = 1;
	draw_connections(f);
	menu(f);
}

void	zoom(t_fdf *f, int key)
{
	f->color = 0;
	draw_connections(f);
	if (key == NUM_PAD_PLUS || key == PLUS)
		f->s_u += 1;
	else if (key == NUM_PAD_MIN || key == MIN)
		if (f->s_u > 3)
			f->s_u -= 1;
	f->color = MENU_SQ;
	draw_connections(f);
	menu(f);
}

void	move(t_fdf *f, int key)
{
	f->color = 0;
	draw_connections(f);
	if (key == AR_R)
		f->sft_w += 10;
	else if (key == AR_L)
		f->sft_w -= 10;
	else if (key == AR_U)
		f->sft_h -= 10;
	else if (key == AR_D)
		f->sft_h += 10;
	f->color = MENU_SQ;
	draw_connections(f);
	menu(f);
}

void	projections(t_fdf *f, int key)
{
	f->color = 0;
	draw_connections(f);
	if (key == P)
	{
		f->proj = 0;
		f->ox = 390;
		f->oy = 70;
		f->sft_h = 0;
		f->sft_w = 0;
	}
	else if (key == I)
	{
		f->proj = 1;
		f->ox = 390;
		f->oy = (1440 - 45) / 2;
		f->sft_h = 0;
		f->sft_w = 0;
	}
	f->color = MENU_SQ;
	draw_connections(f);
	menu(f);
}

void	colors(t_fdf *f, int key)
{
	f->color = 0;
	draw_connections(f);
	if (key == NUM_1 || key == NUM_PAD_1)
	{
		f->c1 = RGB_R;
		f->c2 = RGB_G;
		f->c3 = RGB_B;
	}
	if (key == NUM_2 || key == NUM_PAD_2)
	{
		f->c1 = BLUE_L;
		f->c2 = BLUE_M;
		f->c3 = BLUE_D;
	}
	if (key == NUM_3 || key == NUM_PAD_3)
	{
		f->c1 = BE_B;
		f->c2 = BE_Y;
		f->c3 = BE_R;
	}
	f->color = 1;
	draw_connections(f);
	menu(f);
}
