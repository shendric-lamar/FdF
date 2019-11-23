/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shendric <shendric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:49:41 by shendric          #+#    #+#             */
/*   Updated: 2019/10/03 21:43:34 by shendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keys(int key, void *param)
{
	t_fdf *f;

	f = (t_fdf*)param;
	if (key == ESC)
	{
		free_all(f);
		exit(1);
	}
	else if (key == NUM_PAD_PLUS || key == NUM_PAD_MIN || key == PLUS ||
			key == MIN)
		zoom(f, key);
	else if (key == AR_R || key == AR_L || key == AR_U || key == AR_D)
		move(f, key);
	else if (key == P || key == I)
		projections(f, key);
	else if (key == NUM_1 || key == NUM_2 || key == NUM_3 || key == NUM_PAD_1 ||
		key == NUM_PAD_2 || key == NUM_PAD_3)
		colors(f, key);
	else if (key == H || key == L)
		height(f, key);
	else if (key == D)
		dots(f);
	return (0);
}

void	draw(t_fdf *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->win_w, f->win_h,
		"fdf - spozzi & shendric");
	menu(f);
	draw_connections(f);
	mlx_key_hook(f->win, keys, f);
	mlx_loop(f->mlx);
}

void	read_store_file(int fd, t_fdf *f)
{
	char	*buf;
	size_t	ret;
	char	*tab;
	char	**map_char;

	if (!(buf = (char *)malloc(sizeof(char) * f->size)))
		ft_error(1);
	if (!(ret = read(fd, buf, f->size)))
		ft_error(1);
	buf[ret] = '\0';
	tab = ft_strdup(buf);
	str_replace(tab, f);
	map_char = ft_strsplit(tab, ' ');
	str_to_int(map_char, f);
	free(buf);
	free(tab);
	f->i = -1;
	while (map_char[++f->i])
		free(map_char[f->i]);
	free(map_char);
}

void	init_struct(t_fdf *f)
{
	f->flag2 = 0;
	f->line = NULL;
	f->mlx = NULL;
	f->win = NULL;
	f->win_h = 1440 - 45;
	f->win_w = 2560;
	f->map = NULL;
	f->map_h = 0;
	f->map_w = 0;
	f->flag = 0;
	f->ox = 390;
	f->oy = 70;
	f->s_u = 10;
	f->color = MENU_SQ;
	f->sft_h = 0;
	f->sft_w = 0;
	f->menu_x0 = 6;
	f->menu_x1 = 334;
	f->proj = 0;
	f->dots = 0;
	f->c1 = WHITE;
	f->c2 = WHITE;
	f->c3 = WHITE;
	f->h = 1;
}

int		main(int ac, char **av)
{
	t_fdf	f;
	int		fd;

	init_struct(&f);
	fd = open(av[1], O_RDONLY);
	map_dimensions(fd, &f);
	close(fd);
	if (ac == 2)
	{
		if (!(f.map = (int **)malloc(sizeof(int *) * f.map_h)))
			ft_error(1);
		fd = open(av[1], O_RDONLY);
		read_store_file(fd, &f);
		close(fd);
		draw(&f);
	}
	else
		ft_putendl("usage: ./fdf map_folder/map_name");
}
