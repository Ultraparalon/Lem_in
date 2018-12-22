/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:30:32 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/10 15:30:34 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		vs_img_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= img->height)
		return ;
	img->addr[x + (y << 11)] = color;
}

static t_vector	*vs_vecdup(t_vector *vec)
{
	t_vector *rat;

	if (!(rat = malloc(sizeof(t_vector))))
		ft_error("can not allocate memory.");
	rat->x = vec->x;
	rat->y = vec->y;
	rat->z = vec->z;
	rat->clr = vec->clr;
	return (rat);
}

void			vs_draw_line(t_img *img, t_vector *v1, t_vector *v2)
{
	t_draw dr;

	dr.delta_x = ABS(((int)v2->x - (int)v1->x));
	dr.delta_y = ABS(((int)v2->y - (int)v1->y));
	dr.sign_x = (int)v1->x < (int)v2->x ? 1 : -1;
	dr.sign_y = (int)v1->y < (int)v2->y ? 1 : -1;
	dr.border1 = dr.delta_x - dr.delta_y;
	while ((int)v1->x != (int)v2->x || (int)v1->y != (int)v2->y)
	{
		vs_img_set_pixel(img, (int)v1->x, (int)v1->y, v1->clr);
		dr.border2 = dr.border1 << 1;
		if (dr.border2 > -dr.delta_y)
		{
			dr.border1 -= dr.delta_y;
			v1->x += dr.sign_x;
		}
		if (dr.border2 < dr.delta_x)
		{
			dr.border1 += dr.delta_x;
			v1->y += dr.sign_y;
		}
	}
}

void			vs_draw_rect(t_map *map, t_vector *vec, t_vector *end)
{
	int			height;
	t_vector	*d_vec;
	t_vector	*d_end;

	height = 40;
	while (height--)
	{
		d_vec = vs_vecdup(vec);
		d_end = vs_vecdup(end);
		vs_draw_line(map->pole, d_vec, d_end);
		vec->y += 1;
		end->y += 1;
		free(d_vec);
		free(d_end);
	}
}

void			vs_draw_round(t_img *img, t_vector *vec, int r)
{
	int x;
	int y;
	int delta;
	int error;

	x = 0;
	y = r;
	delta = 1 - 2 * r;
	error = 0;
	while (y >= 0)
	{
		vs_img_set_pixel(img, vec->x + x, vec->y + y, 0);
		vs_img_set_pixel(img, vec->x + x, vec->y - y, 0);
		vs_img_set_pixel(img, vec->x - x, vec->y + y, 0);
		vs_img_set_pixel(img, vec->x - x, vec->y - y, 0);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
			delta += 2 * ++x + 1;
		else if ((delta > 0) && (error > 0))
			delta -= 2 * --y + 1;
		else
			delta += 2 * (++x - y--);
	}
}
