/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:34:11 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/16 17:35:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_crd		*vs_list_crd_ant(t_crd *crd, char *ant)
{
	while (crd)
	{
		if (crd->ant && !ft_strcmp(crd->ant, ant))
		{
			ft_strdel(&crd->ant);
			return (crd);
		}
		crd = crd->next;
	}
	return (NULL);
}

void		vs_list_ants_add(t_ants **dest, t_ants *new)
{
	if (new)
	{
		new->next = *dest;
		*dest = new;
	}
}
