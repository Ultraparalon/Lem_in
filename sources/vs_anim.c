/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:09:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/15 16:09:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_img_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= img->height)
		return ;
	img->addr[x + (y << 11)] = color;
}

static void	vs_draw_ant(t_img *img, int x, int y)
{
	ft_img_set_pixel(img, x, y, 0xFFFFFF);
	ft_img_set_pixel(img, x + 1, y + 1, 0xFFFFFF);
	ft_img_set_pixel(img, x - 1, y + 1, 0xFFFFFF);
	ft_img_set_pixel(img, x - 1, y - 1, 0xFFFFFF);
	ft_img_set_pixel(img, x + 1, y - 1, 0xFFFFFF);
	ft_img_set_pixel(img, x - 2, y + 1, 0xFFFFFF);
	ft_img_set_pixel(img, x + 2, y + 1, 0xFFFFFF);
	ft_img_set_pixel(img, x - 1, y + 2, 0xFFFFFF);
	ft_img_set_pixel(img, x + 1, y + 2, 0xFFFFFF);
	ft_img_set_pixel(img, x - 1, y + 3, 0xFFFFFF);
	ft_img_set_pixel(img, x - 2, y + 3, 0xFFFFFF);
	ft_img_set_pixel(img, x + 1, y + 3, 0xFFFFFF);
	ft_img_set_pixel(img, x + 2, y + 3, 0xFFFFFF);
	ft_img_set_pixel(img, x, y + 4, 0xFFFFFF);
	ft_img_set_pixel(img, x - 1, y + 4, 0xFFFFFF);
	ft_img_set_pixel(img, x + 1, y + 4, 0xFFFFFF);
	ft_img_set_pixel(img, x - 2, y + 5, 0xFFFFFF);
	ft_img_set_pixel(img, x + 2, y + 5, 0xFFFFFF);
}

static int	vs_anim_line(t_img *img, t_vector *v1, t_vector *v2, t_draw *dr)
{
	if ((int)v1->x != (int)v2->x || (int)v1->y != (int)v2->y)
	{
		vs_draw_ant(img, (int)v1->x, (int)v1->y);
		dr->border2 = dr->border1 << 1;
		if (dr->border2 > -dr->delta_y)
		{
			dr->border1 -= dr->delta_y;
			v1->x += dr->sign_x;
		}
		if (dr->border2 < dr->delta_x)
		{
			dr->border1 += dr->delta_x;
			v1->y += dr->sign_y;
		}
		return (1);
	}
	return (0);
}

static void	vs_list_ant_del(t_ants **ant)
{
	t_ants *tmp;

	while (*ant)
	{
		tmp = *ant;
		*ant = tmp->next;
		free(tmp->start);
		free(tmp->end);
		free(tmp->dr);
		free(tmp);
		tmp = NULL;
	}
	ant = NULL;
}

void		vs_anim_ant(t_map *map, t_ants *ant)
{
	int check;

	check = 0;
	while (ant)
	{
		if (vs_anim_line(map->pole, ant->start, ant->end, ant->dr))
			check++;
		ant = ant->next;
	}
	if (!check)
		vs_list_ant_del(&map->ants);
}
