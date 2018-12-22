/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:34:43 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/23 17:34:45 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_push_ant(t_data *data, t_path *path, int ant)
{
	if (path)
	{
		ft_push_ant(data, path->next, path->ant);
		path->ant = ant;
		if (path->ant)
		{
			ft_printf("L%u-%s ", path->ant, path->name);
		}
		if (!ft_strcmp(data->end->name, path->name) && ant)
		{
			data->total++;
		}
	}
}

static int	ft_ways(t_data *data, t_way *way, int curr)
{
	while (way)
	{
		ft_push_ant(data, way->path, (curr <= data->ammount) ? curr : 0);
		way = way->next;
		curr++;
	}
	ft_printf("\n");
	return (curr);
}

void		ft_process_unit(t_data *data)
{
	int curr;

	curr = 1;
	if (!data->ways)
		ft_error("no path\n");
	while (data->total < data->ammount)
	{
		curr = ft_ways(data, data->ways, curr);
	}
}
