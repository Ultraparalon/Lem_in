/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_true_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:09:04 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/18 13:09:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_deadend(t_data *data, t_path *way)
{
	while (way)
	{
		if (!ft_strcmp(data->end->name, way->name))
			return (0);
		way = way->next;
	}
	return (1);
}

static t_path	*ft_compare_ways(t_data *data, t_path *old, t_path *new)
{
	if (!old)
		return (new);
	if (ft_deadend(data, new))
	{
		ft_list_del_path(&new);
		return (old);
	}
	if (ft_deadend(data, old))
	{
		ft_list_del_path(&old);
		return (new);
	}
	if (ft_list_path_size(old) > ft_list_path_size(new))
	{
		ft_list_del_path(&old);
		return (new);
	}
	else
	{
		ft_list_del_path(&new);
		return (old);
	}
}

t_path			*ft_true_path(t_data *d, t_path *o, char *side, t_path *s_path)
{
	t_crd	*new;
	t_path	*path;

	path = NULL;
	new = ft_list_crd_find(d->crds, side);
	path = ft_compare_ways(d, o, ft_search_way(d, new, s_path));
	return (path);
}
