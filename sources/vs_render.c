/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:30:20 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/10 17:30:22 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	vs_draw_pipes(t_map *map, t_pipe *pipe)
{
	t_vector *vec1;
	t_vector *vec2;

	while (pipe)
	{
		vec1 = vs_make_vector(pipe->a, map);
		vec2 = vs_make_vector(pipe->b, map);
		vs_draw_line(map->pole, vec1, vec2);
		pipe = pipe->next;
		free(vec1);
		free(vec2);
	}
}

static void	vs_draw_spots(t_map *map, t_crd *crd)
{
	t_vector *vec;

	while (crd)
	{
		vec = vs_make_vector(crd, map);
		vs_draw_round(map->pole, vec, map->in.size >> 2);
		vs_draw_round(map->pole, vec, map->in.size >> 3);
		vs_draw_round(map->pole, vec, 2);
		crd = crd->next;
		free(vec);
	}
}

static void	vs_draw_ammount(t_map *map)
{
	t_vector	*v;
	char		*str;

	v = vs_make_vector(map->start, map);
	str = ft_itoa(map->tot_ammount - map->curr_ammount);
	mlx_string_put(map->mlx, map->window, v->x, v->y + 120, 0xFFFFFF, str);
	free(v);
	free(str);
}

static void	vs_draw_info(t_map *map, t_crd *crd)
{
	t_vector *vec;

	while (crd)
	{
		vec = vs_vector(crd->z, crd->x, crd->y, map);
		mlx_string_put(map->mlx, map->window,
			vec->x, vec->y + 100, 0xFFFFFF, crd->name);
		if (!map->ants && crd->ant)
			mlx_string_put(map->mlx, map->window,
				vec->x, vec->y + 120, 0xFFFFFF, crd->ant);
		crd = crd->next;
		free(vec);
	}
	vs_draw_ammount(map);
}

void		vs_render(t_map *map)
{
	vs_draw_pipes(map, map->pipes);
	vs_draw_spots(map, map->crds);
	if (map->ants)
		vs_anim_ant(map, map->ants);
	mlx_put_image_to_window(map->mlx, map->window, map->pole->img, 0, STAT_H);
	vs_draw_info(map, map->crds);
	vs_draw_status(map);
}
