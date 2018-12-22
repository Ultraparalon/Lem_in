/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:23 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 09:38:53 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef	struct		s_path
{
	unsigned int	ant;
	char			*name;
	void			*next;
}					t_path;

typedef struct		s_pipe
{
	char			*a;
	char			*b;
	void			*next;
}					t_pipe;

typedef struct		s_crd
{
	int				y;
	int				x;
	int				z;
	char			*name;
	t_pipe			*pipes;
	void			*next;
}					t_crd;

typedef struct		s_way
{
	t_path			*path;
	void			*next;
}					t_way;

typedef struct		s_data
{
	int				ammount;
	int				total;
	t_crd			*start;
	t_crd			*end;
	t_crd			*crds;
	t_crd			*curr;
	t_pipe			*pipe;
	t_way			*ways;
}					t_data;

void				ft_read_input(t_data *data);
int					ft_is_str_num(char *str);
int					ft_wizard(t_data *data);
char				*ft_get_coords(t_data *data);
void				ft_get_pipes(t_data *data, char *tmp);
t_path				*ft_find_way(t_data *data, t_crd *begin);
void				ft_get_ways(t_data *data, t_pipe *ways);
void				ft_process_unit(t_data *data);
int					ft_list_path_size(t_path *lst);
void				ft_list_del_path(t_path **path);
void				ft_list_dellast_path(t_path	**path);
t_path				*ft_list_new_path(char *data);
void				ft_list_add_path(t_path **alst, t_path *new);
t_crd				*ft_list_crd_find(t_crd *start, char *name);
void				ft_list_crd_add(t_crd **alst, t_crd *new);
int					ft_list_crd_cmp(t_crd *start, int y, int x, int z);
void				ft_list_pipe_add(t_pipe **alst, t_pipe *new);
t_pipe				*ft_list_pipe_new(char *a, char *b);
void				ft_list_pipe_del(t_pipe *pipe);
t_pipe				*ft_list_pipe_cmp(t_pipe *start, t_pipe *pipe);
void				ft_output(t_data *data);
t_path				*ft_true_path(t_data *data,
	t_path *old, char *side, t_path *s_path);
t_path				*ft_search_way(t_data *data, t_crd *curr, t_path *s_path);
void				ft_read_comment(char **str);

#endif
