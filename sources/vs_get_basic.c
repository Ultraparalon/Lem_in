/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_get_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:40:35 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/10 16:40:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	vs_warning_manage(char *str)
{
	ft_strdel(&str);
	get_next_line(0, &str);
	ft_strdel(&str);
}

static void	vs_get_ammount(t_map *map)
{
	char	*tmp;

	while (1)
	{
		if (get_next_line(0, &tmp) < 1)
			ft_error("no input");
		if (ft_strstr(tmp, "error:"))
			ft_error(&tmp[7]);
		if (tmp[0] == '#')
		{
			ft_strdel(&tmp);
			continue ;
		}
		if (!ft_strcmp(tmp, "warning!"))
		{
			vs_warning_manage(tmp);
			continue ;
		}
		if (!ft_atoi(tmp))
			ft_error("wrong input");
		map->tot_ammount = ft_atoi(tmp);
		map->curr_ammount = 0;
		free(tmp);
		break ;
	}
}

void		vs_get_basic(t_map *map)
{
	vs_get_ammount(map);
	vs_get_crds(map);
	vs_get_pipes(map);
}
