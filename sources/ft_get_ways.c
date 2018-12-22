/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:15:01 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/16 18:15:02 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_way	*ft_list_way_new(t_path *path)
{
	t_way	*new;

	if (!(new = malloc(sizeof(t_way))))
		ft_error("can not allocate memory.");
	new->path = path;
	new->next = NULL;
	return (new);
}

static void		ft_list_way_add(t_way **dest, t_way *new)
{
	if (new)
	{
		new->next = *dest;
		*dest = new;
	}
}

static t_crd	*ft_get_begin(t_data *data, t_pipe *way)
{
	t_crd *rat;

	if (ft_strcmp(data->start->name, way->a))
		rat = ft_list_crd_find(data->crds, way->a);
	else
		rat = ft_list_crd_find(data->crds, way->b);
	return (rat);
}

void			ft_get_ways(t_data *data, t_pipe *ways)
{
	t_path	*path;
	t_crd	*begin;

	while (ways)
	{
		begin = ft_get_begin(data, ways);
		data->curr = begin;
		path = ft_find_way(data, begin);
		if (path)
			ft_list_way_add(&data->ways, ft_list_way_new(path));
		ways = ways->next;
	}
}
