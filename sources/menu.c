/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:54:38 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 19:15:10 by spozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_text(t_fdf *f)
{
	mlx_string_put(f->mlx, f->win, 40, 473, \
		TEXT, "Made by Spozzi & Shendric");
	mlx_string_put(f->mlx, f->win, 90, 15, MENU_SQ, "C O N T R O L S");
	mlx_string_put(f->mlx, f->win, 20, 50, TEXT, "ZOOM:");
	mlx_string_put(f->mlx, f->win, 100, 50, MENU_SQ, "+ -");
	mlx_string_put(f->mlx, f->win, 20, 70, TEXT, "HEIGHT:");
	mlx_string_put(f->mlx, f->win, 100, 69, MENU_SQ, "h l");
	mlx_string_put(f->mlx, f->win, 20, 90, TEXT, "MOVE:");
	mlx_string_put(f->mlx, f->win, 95, 90, TEXT, "arrows");
	mlx_string_put(f->mlx, f->win, 35, 140, MENU_SQ, \
		"C O L O R  P A L E T T E S");
	mlx_string_put(f->mlx, f->win, 35, 173, TEXT, "rgb [1]");
	mlx_string_put(f->mlx, f->win, 135, 173, TEXT, "blue [2]");
	mlx_string_put(f->mlx, f->win, 230, 173, TEXT, "nature [3]");
	mlx_string_put(f->mlx, f->win, 60, 270, MENU_SQ, \
		"P R O J E C T I O N S");
	mlx_string_put(f->mlx, f->win, 20, 305, TEXT, \
		"CHANGE PROJECTION: I - P - D\n");
	mlx_string_put(f->mlx, f->win, 40, 350, MENU_SQ, "ISOMETRIC");
	mlx_string_put(f->mlx, f->win, 208, 350, MENU_SQ, "PARALLEL");
	mlx_string_put(f->mlx, f->win, 145, 413, MENU_SQ, "DOTS");
}

void	colors_select(t_fdf *f)
{
	colors_draw(f, 20, 200, RGB_B);
	colors_draw(f, 50, 200, RGB_G);
	colors_draw(f, 80, 200, RGB_R);
	colors_draw(f, 125, 200, BLUE_D);
	colors_draw(f, 155, 200, BLUE_M);
	colors_draw(f, 185, 200, BLUE_L);
	colors_draw(f, 230, 200, BE_B);
	colors_draw(f, 260, 200, BE_Y);
	colors_draw(f, 290, 200, BE_R);
}

void	menu_layout(t_fdf *f, int flag)
{
	if (flag == 1)
		menu_draw(f, 6, 504, BORDER);
	else if (flag == 0)
	{
		menu_draw(f, 45, 118, MENU_SQ);
		menu_draw(f, 170, 250, MENU_SQ);
		menu_draw(f, 300, 460, MENU_SQ);
		menu_draw(f, 470, 500, BLUE_M);
	}
	else if (flag == -1)
	{
		proj_draw(f, 14, 168, BLUE_M);
		proj_draw(f, 172, 326, BLUE_M);
		proj_draw_dots(f, 14, 326, BLUE_M);
	}
	draw_boxes_zoom(f, 116, 134, BLUE_M);
	draw_boxes_zoom(f, 96, 114, BLUE_M);
	draw_boxes_height(f, 116, 134, BLUE_M);
	draw_boxes_height(f, 96, 114, BLUE_M);
}

void	menu(t_fdf *f)
{
	menu_layout(f, 1);
	menu_layout(f, 0);
	menu_layout(f, -1);
	menu_text(f);
	colors_select(f);
}
