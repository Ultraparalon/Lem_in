/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:08:40 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/24 12:08:43 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_collision(t_path *path, char *spot, char *end)
{
	while (path)
	{
		if (!ft_strcmp(path->name, end))
			return (1);
		if (!ft_strcmp(path->name, spot))
			return (0);
		path = path->next;
	}
	return (1);
}

static int	ft_check(t_way *way, t_path *path, char *spot, char *end)
{
	while (way)
	{
		if (!ft_collision(way->path->next, spot, end))
			return (0);
		way = way->next;
	}
	if (!ft_collision(path, spot, end))
		return (0);
	return (1);
}

t_path		*ft_search_way(t_data *data, t_crd *curr, t_path *s_path)
{
	t_pipe	*pipe;
	t_path	*path;

	path = NULL;
	if (!ft_strcmp(data->start->name, curr->name))
		return (NULL);
	if (!ft_strcmp(curr->name, data->end->name))
		return (ft_list_new_path(curr->name));
	pipe = curr->pipes;
	ft_list_add_path(&s_path, ft_list_new_path(curr->name));
	while (pipe)
	{
		if (ft_strcmp(pipe->a, curr->name)
			&& ft_check(data->ways, s_path, pipe->a, data->end->name))
			path = ft_true_path(data, path, pipe->a, s_path);
		else if (ft_strcmp(pipe->b, curr->name)
			&& ft_check(data->ways, s_path, pipe->b, data->end->name))
			path = ft_true_path(data, path, pipe->b, s_path);
		pipe = pipe->next;
	}
	ft_list_dellast_path(&s_path);
	ft_list_add_path(&path, ft_list_new_path(curr->name));
	return (path);
}

static int	ft_check_end(t_path *path, char *end)
{
	while (path)
	{
		if (!ft_strcmp(path->name, end))
			return (1);
		path = path->next;
	}
	return (0);
}

t_path		*ft_find_way(t_data *data, t_crd *begin)
{
	t_path	*s_path;
	t_path	*path;

	s_path = NULL;
	path = ft_search_way(data, begin, s_path);
	if (ft_check_end(path, data->end->name))
		return (path);
	ft_list_del_path(&path);
	return (NULL);
}
