/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_crd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:19:29 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/24 13:19:31 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_crd	*ft_list_crd_find(t_crd *start, char *name)
{
	while (start)
	{
		if (!ft_strcmp(start->name, name))
			return (start);
		start = start->next;
	}
	return (NULL);
}

void	ft_list_crd_add(t_crd **alst, t_crd *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

int		ft_list_crd_cmp(t_crd *start, int y, int x, int z)
{
	while (start)
	{
		if (start->x == x && start->y == y && start->z == z)
			return (1);
		start = start->next;
	}
	return (0);
}
