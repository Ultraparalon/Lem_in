/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:03:41 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/09 18:03:42 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static t_img	*vs_new_img(void *mlx, int height)
{
	t_img *img;

	if (!(img = malloc(sizeof(t_img))))
		ft_error("couldn't allocate memory");
	img->height = height;
	if (!(img->img = mlx_new_image(mlx, W_WIDTH, height)))
		ft_error("couldn't create image");
	img->addr = (int *)mlx_get_data_addr(img->img,
		&img->bit_per_pix, &img->size_line, &img->endian);
	return (img);
}

static t_map	*vs_create(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		ft_error("couldn't allocate memory");
	if (!(map->mlx = mlx_init()))
		ft_error("couldn't init");
	if (!(map->window = mlx_new_window(map->mlx, W_WIDTH, W_HEIGHT, "Lem-in")))
		ft_error("couldn't init");
	map->stat = vs_new_img(map->mlx, STAT_H);
	map->pole = vs_new_img(map->mlx, POLE_H);
	vs_texture_stat(map->stat->addr);
	map->bg_pole = vs_texture_pole();
	return (map);
}

static void		vs_init(t_map *map)
{
	map->in.x_axis = 0;
	map->in.y_axis = 0;
	map->in.z_axis = 0;
	map->in.x = 0;
	map->in.y = 0;
	map->x = 9;
	map->y = 9;
	map->total = 0;
	map->in.size = (W_WIDTH / map->x) >> 2;
	map->in.sidex = W_WIDTH >> 1;
	map->in.sidey = POLE_H >> 1;
	map->in.pause = 0;
	map->crds = NULL;
	map->pipes = NULL;
	map->start = NULL;
	map->end = NULL;
	map->ants = NULL;
	map->in.ants = &map->ants;
}

int				main(void)
{
	t_map *map;

	map = vs_create();
	mlx_string_put(map->mlx, map->window, 5, 5, 0xFFFFFF, "Loading...");
	vs_init(map);
	vs_get_basic(map);
	mlx_key_hook(map->window, vs_deal_key, map);
	mlx_hook(map->window, 17, 0, vs_red_button, map);
	mlx_hook(map->window, 4, 0, hook_mousedown, &map->in);
	mlx_hook(map->window, 5, 0, hook_mouseup, &map->in);
	mlx_hook(map->window, 6, 0, hook_mousemove, &map->in);
	mlx_loop_hook(map->mlx, vs_loop, map);
	mlx_loop(map->mlx);
	return (0);
}
