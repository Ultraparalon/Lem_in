/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:04:29 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/22 16:04:30 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_crd	*ft_new_crd(char **card)
{
	t_crd	*crd;

	if (!(crd = malloc(sizeof(t_crd))))
		ft_error("can not allocate memory.");
	crd->name = ft_strdup(card[0]);
	crd->y = ft_atoi(card[1]);
	crd->x = ft_atoi(card[2]);
	if (card[3])
	{
		if (ft_is_str_num(card[3]))
			ft_error("bad z-coordinate");
		if (card[4])
			ft_error("bad coordinates");
		crd->z = ft_atoi(card[3]);
	}
	else
		crd->z = 0;
	crd->pipes = NULL;
	crd->next = NULL;
	return (crd);
}

static t_crd	*ft_get_crd(char *str)
{
	char	**card;
	t_crd	*crd;

	card = ft_strsplit(str, ' ');
	if (!card[0] || !card[1] || !card[2])
		ft_error("bad coordinates");
	if (ft_strstr(card[0], "error") || ft_strstr(card[0], "warning"))
		ft_error("invalid name");
	if (ft_count_c(card[0], '-'))
		ft_error("symbol '-' is unacceptable!");
	if (ft_is_str_num(card[1]))
		ft_error("bad y-coordinate");
	if (ft_is_str_num(card[2]))
		ft_error("bad x-coordinate");
	if (card[0][0] == 'L')
		ft_error("coordinates name cann't begin with 'L'");
	crd = ft_new_crd(card);
	ft_card_destructor((void **)card);
	return (crd);
}

static void		ft_add_crd(t_crd **spec, char *tmp, t_data *data)
{
	t_crd	*crd;

	if (spec)
	{
		ft_strdel(&tmp);
		get_next_line(0, &tmp);
		crd = ft_get_crd(tmp);
		if (*spec)
			ft_error("already exist");
		*spec = crd;
	}
	else
		crd = ft_get_crd(tmp);
	if (ft_list_crd_find(data->crds, crd->name))
		ft_error("already exist");
	if (ft_list_crd_cmp(data->crds, crd->y, crd->x, crd->z))
		ft_error("coordinates already occupied");
	ft_list_crd_add(&data->crds, crd);
	ft_strdel(&tmp);
}

static int		ft_next_stage(char *tmp)
{
	if (ft_count_c(tmp, '-') && !ft_count_c(tmp, ' '))
		return (1);
	return (0);
}

char			*ft_get_coords(t_data *data)
{
	char	*tmp;

	tmp = NULL;
	while (1)
	{
		if (get_next_line(0, &tmp) < 1)
			ft_error("no coordinates");
		if (ft_next_stage(tmp))
			return (tmp);
		if (*tmp == '#')
		{
			if (!ft_strcmp(tmp, "##start"))
				ft_add_crd(&data->start, tmp, data);
			else if (!ft_strcmp(tmp, "##end"))
				ft_add_crd(&data->end, tmp, data);
			else
				ft_read_comment(&tmp);
		}
		else
			ft_add_crd(NULL, tmp, data);
	}
	ft_strdel(&tmp);
	return (NULL);
}
