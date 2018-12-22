/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 18:32:22 by vkaidans          #+#    #+#             */
/*   Updated: 2018/08/02 18:32:23 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_pipe	*ft_list_pipe_cmp(t_pipe *start, t_pipe *pipe)
{
	while (start)
	{
		if ((!ft_strcmp(start->a, pipe->a) && !ft_strcmp(start->b, pipe->b))
			|| (!ft_strcmp(start->b, pipe->a) && !ft_strcmp(start->a, pipe->b)))
			return (start);
		start = start->next;
	}
	return (NULL);
}

void	ft_list_pipe_add(t_pipe **alst, t_pipe *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_pipe	*ft_list_pipe_new(char *a, char *b)
{
	t_pipe	*pipe;

	if (!a || !b)
		ft_error("bad pipe");
	if (!(pipe = malloc(sizeof(t_pipe))))
		ft_error("can not allocate memory.");
	pipe->a = ft_strdup(a);
	pipe->b = ft_strdup(b);
	pipe->next = NULL;
	return (pipe);
}

void	ft_list_pipe_del(t_pipe *pipe)
{
	free(pipe->a);
	free(pipe->b);
	free(pipe->next);
	free(pipe);
}
