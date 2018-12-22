/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:18:02 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/12 20:18:03 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		vs_texture_stat(int *back)
{
	int i;

	i = W_WIDTH * STAT_H;
	while (i--)
		*back++ = 0x555577;
	i = W_WIDTH << 2;
	back--;
	while (i--)
		*back-- = 0x5555FF;
}

static int	vs_magic(int x)
{
	if (x == 0)
		return (0x8B4513);
	else if (x == 1)
		return (0xD2691E);
	else if (x == 2)
		return (0xA0522D);
	else if (x == 3)
		return (0x8B4513);
	else if (x == 4)
		return (0xB8860B);
	return (0xCD853F);
}

static void	vs_fill(int *back)
{
	int				y;
	int				x;

	y = -1;
	while (++y < POLE_H)
	{
		x = -1;
		while (++x < W_WIDTH)
			*back++ = vs_magic(rand() % 120);
	}
}

void		vs_upgrade(int *back)
{
	int y;
	int x;

	vs_fill(back);
	y = -1;
	while (++y < POLE_H)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			*back = vs_contrast(-y >> 3, *back);
			back++;
		}
	}
}

int			*vs_texture_pole(void)
{
	int *back;

	if (!(back = (int *)malloc(sizeof(int) * (W_WIDTH * POLE_H))))
		ft_error("couldn't allocate memory");
	vs_upgrade(back);
	return (back);
}
