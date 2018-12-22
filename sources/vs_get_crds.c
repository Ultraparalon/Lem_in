/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_get_crds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:13:34 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/13 17:13:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_crd			*vs_list_crd_find(t_crd *crds, char *name)
{
	while (crds)
	{
		if (!ft_strcmp(crds->name, name))
			return (crds);
		crds = crds->next;
	}
	return (NULL);
}

static void		vs_list_crd_add(t_crd **dest, t_crd *new)
{
	if (new)
	{
		new->next = *dest;
		*dest = new;
	}
}

static t_crd	*vs_list_crd_new(char *str)
{
	char	**card;
	t_crd	*crd;

	card = ft_strsplit(str, ' ');
	if (!(crd = malloc(sizeof(t_crd))))
		ft_error("can not allocate memory.");
	crd->name = ft_strdup(card[0]);
	crd->y = ft_atoi(card[1]);
	crd->x = ft_atoi(card[2]);
	if (card[3])
		crd->z = ft_atoi(card[3]);
	else
		crd->z = 0;
	crd->ant = NULL;
	crd->next = NULL;
	ft_card_destructor((void **)card);
	return (crd);
}

static void		vs_add_crd(t_crd **spec, char *tmp, t_map *map)
{
	t_crd *crd;

	if (spec)
	{
		free(tmp);
		get_next_line(0, &tmp);
		crd = vs_list_crd_new(tmp);
		*spec = crd;
	}
	else
		crd = vs_list_crd_new(tmp);
	vs_list_crd_add(&map->crds, crd);
	free(tmp);
}

void			vs_get_crds(t_map *map)
{
	char	*tmp;

	while (1)
	{
		get_next_line(0, &tmp);
		if (ft_strstr(tmp, "error:"))
			ft_error(&tmp[7]);
		if (!ft_strlen(tmp))
			break ;
		if (*tmp == '#')
		{
			if (!ft_strcmp(tmp, "##start"))
				vs_add_crd(&map->start, tmp, map);
			else if (!ft_strcmp(tmp, "##end"))
				vs_add_crd(&map->end, tmp, map);
			else
				free(tmp);
		}
		else
			vs_add_crd(NULL, tmp, map);
	}
	free(tmp);
}
