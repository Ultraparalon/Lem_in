/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_next_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:03:51 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/16 16:03:56 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_draw		*vs_make_dr(t_vector *v1, t_vector *v2)
{
	t_draw *dr;

	if (!(dr = malloc(sizeof(t_draw))))
		ft_error("can not allocate memory.");
	dr->delta_x = ABS(((int)v2->x - (int)v1->x));
	dr->delta_y = ABS(((int)v2->y - (int)v1->y));
	dr->sign_x = (int)v1->x < (int)v2->x ? 1 : -1;
	dr->sign_y = (int)v1->y < (int)v2->y ? 1 : -1;
	dr->border1 = dr->delta_x - dr->delta_y;
	return (dr);
}

static void	vs_compare_lem(t_map *map, int curr)
{
	if (curr > map->curr_ammount)
		map->curr_ammount = curr;
}

static void	vs_end_sub(t_map *map, t_crd *crd)
{
	map->total++;
	ft_strdel(&crd->ant);
	crd->ant = ft_itoa(map->total);
}

void		vs_get_ants(t_map *map, t_crd *crd, char **card)
{
	char	**step;
	t_crd	*curr;
	t_ants	*ant;

	while (*card)
	{
		ant = malloc(sizeof(t_ants));
		step = ft_strsplit(*card, '-');
		vs_compare_lem(map, ft_atoi(&step[0][1]));
		if ((curr = vs_list_crd_ant(crd, step[0])))
			ant->start = vs_make_vector(curr, map);
		else
			ant->start = vs_make_vector(map->start, map);
		curr = vs_list_crd_find(crd, step[1]);
		ant->end = vs_make_vector(curr, map);
		ant->dr = vs_make_dr(ant->start, ant->end);
		if (!curr->ant)
			curr->ant = ft_strdup(step[0]);
		if (!ft_strcmp(step[1], map->end->name))
			vs_end_sub(map, map->end);
		ant->next = NULL;
		vs_list_ants_add(&map->ants, ant);
		ft_card_destructor((void **)step);
		card++;
	}
}

void		vs_next_step(t_map *map)
{
	char *tmp;
	char **card;

	if (get_next_line(0, &tmp) < 1)
		return ;
	if (ft_strlen(tmp))
	{
		if (ft_strstr(tmp, "error:"))
			ft_error(&tmp[7]);
		ft_strdel(&map->end->ant);
		card = ft_strsplit(tmp, ' ');
		vs_get_ants(map, map->crds, card);
		ft_card_destructor((void **)card);
	}
	free(tmp);
}
