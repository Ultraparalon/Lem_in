/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:21:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/22 18:22:00 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_pipe	*ft_get_pipe(char *str)
{
	char	**card;
	t_pipe	*pipe;

	card = ft_strsplit(str, '-');
	if (!card[0] || !card[1])
		ft_error("invalid pipe");
	if (ft_strstr(card[0], "error") || ft_strstr(card[0], "warning")
		|| ft_strstr(card[1], "error") || ft_strstr(card[1], "warning"))
		ft_error("invalid name");
	pipe = ft_list_pipe_new(card[0], card[1]);
	ft_card_destructor((void **)card);
	return (pipe);
}

static void		ft_bad_pipe(t_pipe *pipe, char *str)
{
	ft_printf(str);
	ft_list_pipe_del(pipe);
}

void			ft_get_pipes(t_data *data, char *tmp)
{
	t_pipe	*pipe;

	while (ft_strlen(tmp))
	{
		if (tmp[0] == '#')
			ft_read_comment(&tmp);
		else
		{
			if (ft_count_c(tmp, '-') > 1)
				ft_error("too much '-' symbols in pipe");
			pipe = ft_get_pipe(tmp);
			if (!ft_list_crd_find(data->crds, pipe->a)
				|| !ft_list_crd_find(data->crds, pipe->b))
				ft_bad_pipe(pipe, "warning!\nNo such coordinate.\n");
			else if (ft_list_pipe_cmp(data->pipe, pipe))
				ft_bad_pipe(pipe, "warning!\nPipe already exist.\n");
			else
				ft_list_pipe_add(&data->pipe, pipe);
		}
		ft_strdel(&tmp);
		if (get_next_line(0, &tmp) < 1)
			break ;
	}
	ft_strdel(&tmp);
}
