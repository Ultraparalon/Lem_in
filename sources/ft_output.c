/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:34:40 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/04 16:34:42 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_coords(t_crd *start, t_crd *end, t_crd *crds)
{
	ft_printf("##start\n");
	ft_printf("%s %d %d %d\n", start->name, start->y, start->x, start->z);
	ft_printf("##end\n");
	ft_printf("%s %d %d %d\n", end->name, end->y, end->x, end->z);
	while (crds)
	{
		if (ft_strcmp(crds->name, start->name)
			&& ft_strcmp(crds->name, end->name))
			ft_printf("%s %d %d %d\n", crds->name, crds->y, crds->x, crds->z);
		crds = crds->next;
	}
	ft_putchar('\n');
}

static void	ft_print_pipes(t_pipe *pipe)
{
	while (pipe)
	{
		ft_printf("%s-%s\n", pipe->a, pipe->b);
		pipe = pipe->next;
	}
}

void		ft_output(t_data *data)
{
	ft_printf("%d\n", data->ammount);
	ft_print_coords(data->start, data->end, data->crds);
	ft_print_pipes(data->pipe);
	ft_putchar('\n');
}
