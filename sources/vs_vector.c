/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:01:27 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/10 18:01:28 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include <math.h>

static void		ft_rotate_vector(t_vector *vec, t_input *in)
{
	double		x;
	double		y;
	double		z;

	x = vec->x;
	y = vec->y;
	z = vec->z;
	vec->y = cos(in->y_axis) * x + sin(in->y_axis) * z;
	vec->z = -sin(in->y_axis) * x + cos(in->y_axis) * z;
	z = vec->z;
	vec->x = cos(in->x_axis) * y - sin(in->x_axis) * z;
	vec->z = sin(in->x_axis) * y + cos(in->x_axis) * z;
	x = vec->x;
	y = vec->y;
	vec->x = cos(in->z_axis) * y - sin(in->z_axis) * x;
	vec->y = sin(in->z_axis) * y + cos(in->z_axis) * x;
}

t_vector		*vs_vector(int z, int x, int y, t_map *map)
{
	t_vector *vec;

	vec = malloc(sizeof(t_vector));
	vec->clr = 0x0;
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->x -= (double)((map->x - 1) >> 1);
	vec->y -= (double)((map->y - 1) >> 1);
	vec->x = vec->x * map->in.size;
	vec->y = vec->y * map->in.size;
	vec->z = vec->z * map->in.size;
	ft_rotate_vector(vec, &map->in);
	vec->x += map->in.sidex;
	vec->y += map->in.sidey;
	vec->x = (int)vec->x;
	vec->y = (int)vec->y;
	return (vec);
}

t_vector		*vs_make_vector(t_crd *crd, t_map *map)
{
	return (vs_vector(crd->z, crd->x, crd->y, map));
}
