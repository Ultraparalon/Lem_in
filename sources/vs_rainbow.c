/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:17:35 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/20 14:17:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int	ft_set_colour(int red, int green, int blue)
{
	int colour;

	red <<= 16;
	green <<= 8;
	colour = red + green + blue;
	return (colour);
}

static void	ft_power_up(int *col, int *mor)
{
	*col += *mor;
	if (*col > 255)
	{
		*mor = *col - 256;
		*col = 255;
	}
	else
		*mor = 0;
}

static void	ft_power_down(int *col, int *mor)
{
	*col -= *mor;
	if (*col < 0)
	{
		*mor = ABS(*col);
		*col = 0;
	}
	else
		*mor = 0;
}

static int	ft_colour_morph(int colour, int *mor)
{
	int red;
	int green;
	int blue;

	red = colour >> 16;
	green = (colour >> 8) % 256;
	blue = colour % 256;
	if (red == 255 && blue)
		ft_power_down(&blue, mor);
	else if (red == 255 && green < 255)
		ft_power_up(&green, mor);
	else if (green == 255 && red)
		ft_power_down(&red, mor);
	else if (green == 255 && blue < 255)
		ft_power_up(&blue, mor);
	else if (blue == 255 && green)
		ft_power_down(&green, mor);
	else if (blue == 255 && red < 255)
		ft_power_up(&red, mor);
	return (ft_set_colour(red, green, blue));
}

int			vs_rainbow(int morph, int base_clr)
{
	if (morph > 1536)
		morph %= 1536;
	while (morph > 0)
	{
		base_clr = ft_colour_morph(base_clr, &morph);
		morph--;
	}
	return (base_clr);
}
