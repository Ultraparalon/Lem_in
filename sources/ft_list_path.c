/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:06:25 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/24 19:06:26 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_list_path_size(t_path *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_path	*ft_list_new_path(char *name)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		ft_error("can not allocate memory.");
	new->name = ft_strdup(name);
	new->ant = 0;
	new->next = NULL;
	return (new);
}

void	ft_list_add_path(t_path **alst, t_path *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_list_dellast_path(t_path **path)
{
	t_path *tmp;

	tmp = *path;
	*path = tmp->next;
	free(tmp->name);
	free(tmp);
}

void	ft_list_del_path(t_path **path)
{
	t_path *tmp;

	while (*path)
	{
		tmp = *path;
		*path = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = NULL;
	}
	path = NULL;
}
