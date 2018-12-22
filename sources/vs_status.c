/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:25:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/12 17:25:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	vs_draw_status(t_map *m)
{
	mlx_put_image_to_window(m->mlx, m->window, m->stat->img, 0, 0);
	if (m->ants)
	{
		mlx_string_put(m->mlx, m->window, 10, 10, W, "Move/zoom - locked");
		if (m->curr_ammount % 5 == 0)
			mlx_string_put(m->mlx, m->window, 900, 70, W, "My brudda!");
		else if (m->curr_ammount % 5 == 1)
			mlx_string_put(m->mlx, m->window,
				900, 70, W, "Let's find ur queen!");
		else if (m->curr_ammount % 5 == 2)
			mlx_string_put(m->mlx, m->window, 900, 70, W, "Do u know de wey?");
		else if (m->curr_ammount % 5 == 3)
			mlx_string_put(m->mlx, m->window,
				900, 70, W, "Through path of de divine!");
		else if (m->curr_ammount % 5 == 4)
			mlx_string_put(m->mlx, m->window, 900, 70, W, "Spit ebola on dem!");
	}
	else
		mlx_string_put(m->mlx, m->window, 10, 10, W, "Move/zoom - mouse");
	mlx_string_put(m->mlx, m->window, 10, 30, W, "Next step - 'Space'");
	mlx_string_put(m->mlx, m->window, 10, 50, W, "Background - 'B'");
}
