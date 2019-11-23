/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:58:56 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 21:12:53 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "colors.h"
# include "keys.h"
# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

# define BUF_SIZE 100000

typedef struct	s_fdf
{
	int			flag2;
	int			sft_h;
	int			sft_w;
	char		*line;
	int			size;
	int			i;
	int			j;
	int			k;
	int			l;
	int			s_u;
	int			ox;
	int			oy;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			flag;
	double		m;
	int			b;
	int			tmp;
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			**map;
	int			map_h;
	int			map_w;
	int			color;
	int			menu_x0;
	int			menu_x1;
	int			proj;
	int			dots;
	int			offset_x;
	int			offset_y;
	int			reset;
	int			c1;
	int			c2;
	int			c3;
	int			h;
}				t_fdf;

/*
**			main.c
*/

int				keys(int key, void *param);
void			draw(t_fdf *f);
void			read_store_file(int fd, t_fdf *f);
void			init_struct(t_fdf *f);
int				main(int ac, char **av);

/*
**			draw.c
*/

void			update_x_y(t_fdf *f);
void			draw_line(t_fdf *f);
void			draw_connections(t_fdf *f);

/*
**			functions.c
*/

void			ft_error(int i);
char			*remove_spaces(char *str, t_fdf *f);
void			str_replace(char *str, t_fdf *f);
void			str_to_int(char **map, t_fdf *f);

/*
**			menu.c
*/

void			menu_text(t_fdf *f);
void			controls_boxes(t_fdf *f);
void			colors_select(t_fdf *f);
void			menu_layout(t_fdf *fdf, int flag);
void			menu(t_fdf *f);

/*
**			controls.c
*/

void			height(t_fdf *f, int key);
void			zoom(t_fdf *fdf, int key);
void			move(t_fdf *fdf, int key);
void			projections(t_fdf *fdf, int key);
void			colors(t_fdf *fdf, int key);

/*
**			menu_draw.c
*/

void			draw_boxes_height(t_fdf *f, int x1, int x2, int color);
void			draw_boxes_zoom(t_fdf *fdf, int x1, int x2, int color);
void			colors_draw(t_fdf *fdf, int x, int y, int color);
void			proj_draw(t_fdf *fdf, int x1, int x2, int color);
void			menu_draw(t_fdf *fdf, int y1, int y2, int color);

/*
**			extra.c
*/

void			dots(t_fdf *f);
void			map_dimensions(int fd, t_fdf *f);
void			proj_draw_dots(t_fdf *fdf, int x1, int x2, int color);
void			free_all(t_fdf *f);

#endif
