/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:42:34 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/17 17:42:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int	vs_set_colour(int red, int green, int blue)
{
	int colour;

	red <<= 16;
	green <<= 8;
	colour = red + green + blue;
	return (colour);
}

static int	vs_morph(int spectre, int power)
{
	spectre += power;
	if (spectre < 0)
		spectre = 0;
	if (spectre > 255)
		spectre = 255;
	return (spectre);
}

int			vs_contrast(int power, int colour)
{
	int red;
	int green;
	int blue;

	red = colour >> 16;
	green = (colour >> 8) % 256;
	blue = colour % 256;
	red = vs_morph(red, power);
	green = vs_morph(green, power);
	blue = vs_morph(blue, power);
	return (vs_set_colour(red, green, blue));
}
