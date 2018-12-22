/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wizard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:05:31 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/06 19:05:32 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_read_comment(char **str)
{
	if (str[0][1] != '#')
		ft_putendl(*str);
	ft_strdel(str);
}

static void	ft_data_init(t_data *data)
{
	data->total = 0;
	data->start = NULL;
	data->end = NULL;
	data->crds = NULL;
	data->pipe = NULL;
	data->ways = NULL;
}

int			ft_wizard(t_data *data)
{
	ft_data_init(data);
	ft_read_input(data);
	ft_get_ways(data, data->start->pipes);
	ft_output(data);
	ft_process_unit(data);
	return (0);
}
