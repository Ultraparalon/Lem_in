/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_get_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:13:50 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/13 17:13:52 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		vs_list_pipe_add(t_pipe **dest, t_pipe *new)
{
	if (new)
	{
		new->next = *dest;
		*dest = new;
	}
}

static t_pipe	*vs_list_pipe_new(t_map *map, char *a, char *b)
{
	t_pipe *pipe;

	if (!(pipe = malloc(sizeof(t_pipe))))
		ft_error("can not allocate memory.");
	pipe->a = vs_list_crd_find(map->crds, a);
	pipe->b = vs_list_crd_find(map->crds, b);
	pipe->next = NULL;
	return (pipe);
}

static t_pipe	*vs_get_pipe(t_map *map, char *str)
{
	char	**card;
	t_pipe	*pipe;

	card = ft_strsplit(str, '-');
	pipe = vs_list_pipe_new(map, card[0], card[1]);
	ft_card_destructor((void **)card);
	return (pipe);
}

void			vs_get_pipes(t_map *map)
{
	char	*tmp;

	while (1)
	{
		get_next_line(0, &tmp);
		if (ft_strstr(tmp, "error:"))
			ft_error(&tmp[7]);
		if (!ft_strlen(tmp))
			break ;
		vs_list_pipe_add(&map->pipes, vs_get_pipe(map, tmp));
		free(tmp);
	}
	free(tmp);
}
