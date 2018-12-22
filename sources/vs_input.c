/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 20:03:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/09 20:03:20 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	vs_img_clear(int *dest, int *src)
{
	int len;

	len = W_WIDTH * POLE_H;
	while (len--)
		*dest++ = *src++;
}

int			vs_loop(t_map *map)
{
	vs_img_clear(map->pole->addr, map->bg_pole);
	vs_render(map);
	return (0);
}

int			vs_red_button(t_map *map)
{
	(void)map;
	exit(0);
	return (0);
}

int			vs_deal_key(int key, t_map *map)
{
	if (key == 49 && !map->ants)
		vs_next_step(map);
	if (key == 11)
		vs_upgrade(map->bg_pole);
	else if (key == 53)
		exit(0);
	return (0);
}
