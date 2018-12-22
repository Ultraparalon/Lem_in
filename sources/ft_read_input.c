/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:49:26 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/06 18:49:34 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_get_ammount(t_data *data)
{
	char	*tmp;

	while (1)
	{
		if (get_next_line(0, &tmp) < 1)
			ft_error("wrong input");
		if (tmp[0] == '#')
		{
			ft_read_comment(&tmp);
			continue ;
		}
		data->ammount = ft_atoi(tmp);
		if (ft_is_str_num(tmp))
			ft_error("not number");
		ft_strdel(&tmp);
		if (data->ammount < 1)
			ft_error("no ants");
		break ;
	}
	return (0);
}

void		ft_find_pipes(t_crd *crd, t_pipe *pipes)
{
	t_pipe *pipe;

	pipe = pipes;
	while (pipe)
	{
		if (!ft_strcmp(pipe->a, crd->name)
			|| !ft_strcmp(pipe->b, crd->name))
			ft_list_pipe_add(&crd->pipes, ft_list_pipe_new(pipe->a, pipe->b));
		pipe = pipe->next;
	}
}

static void	ft_put_pipes(t_data *data)
{
	t_crd *crd;

	crd = data->crds;
	while (crd)
	{
		ft_find_pipes(crd, data->pipe);
		crd = crd->next;
	}
}

void		ft_read_input(t_data *data)
{
	char	*tmp;

	ft_get_ammount(data);
	tmp = ft_get_coords(data);
	if (!data->start || !data->end)
		ft_error("no start/end");
	ft_get_pipes(data, tmp);
	ft_put_pipes(data);
}
