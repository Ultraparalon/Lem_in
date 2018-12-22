/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_input_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:21:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/18 13:21:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			hook_mousedown(int button, int x, int y, t_input *in)
{
	(void)x;
	(void)y;
	in->isdown |= 1 << button;
	if (button == 4 && !*in->ants)
		in->size++;
	else if (button == 5 && !*in->ants && in->size > 1)
		in->size--;
	return (0);
}

int			hook_mouseup(int button, int x, int y, t_input *in)
{
	(void)x;
	(void)y;
	in->isdown &= ~(1 << button);
	return (0);
}

int			hook_mousemove(int x, int y, t_input *in)
{
	in->lastx = in->x;
	in->lasty = in->y;
	in->x = x;
	in->y = y;
	if (in->isdown & (1 << 2) && !*in->ants)
	{
		in->x_axis += (in->lasty - y) / 100.0f;
		in->y_axis -= (in->lastx - x) / 100.0f;
	}
	else if (in->isdown & (1 << 1) && !*in->ants)
	{
		in->sidex -= (in->lastx - x);
		in->sidey -= (in->lasty - y);
	}
	return (0);
}
