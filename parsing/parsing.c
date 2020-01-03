/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/01/03 15:38:24 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef struct	s_ref
{
	char	ref[5];
	int		(*f_ref[5])();
}				t_ref;

int		f_ref_resolution(t_param *hub, char *str)
{
	static int pass = 0;

	if (pass++ > 0)
		return (-1);
	(void)hub;
	(void)str;

	printf("recognized R\n");
	return (1);
}

t_ref		ft_ref_parse(void)
{
	t_ref	ref_parse;

	ref_parse.ref[0] = 'R'; 
	ref_parse.f_ref[0] = f_ref_resolution; 

	return (ref_parse);
}

int			ft_first_vars(t_param *hub, t_gnl *gnl_lst, t_ref ref_parse, int fd)
{
	int			i;
	int			k;
	int			gnl_value;
	char		*gnl_line;

	i = 0;
	while ((gnl_value = ft_gnl(fd, &gnl_line, &gnl_lst)) == 1)
	{
		while (gnl_line[i] == ' ')
			i++;
		if (gnl_line[i] == '1')
			break ;
		k = 0;
		while (gnl_line[i] != ref_parse.ref[k] && k < 1)
			k++;
		gnl_value = (k < 1 ? ref_parse.f_ref[k](hub, &gnl_line[i]) : -1);
		free(gnl_line);
		gnl_line = NULL;
		if (gnl_value == -1)
			break ;
	}
	if (gnl_value == 1)
		return (1);
	ft_remove_all_gnl(&gnl_lst);
	return (ft_error("Map Reference Error", hub));
}

int			ft_good_name(char *filename)
{
	int i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (ft_strcmp(&filename[i], ".cub"))
		return (-1);
	return (open(filename, O_RDONLY));
}

int			ft_parse(t_param *hub, char *filename)
{
	int			fd;
	t_gnl		*gnl_lst;

	if ((fd = ft_good_name(filename)) == -1)
		return (ft_error("Given file not correct", hub));
	if ((gnl_lst = ft_lstnew_gnl(fd)) == NULL)
		return (ft_error("Couldn't allocate [GNL]", hub));
	if (ft_first_vars(hub, gnl_lst, ft_ref_parse(), fd) == -1)
		return (-1);


	/* Being at the center */ hub->space->pos.x = 3.5; hub->space->pos.y = 3.5;
	/* Watching North */ hub->space->dir.x = 0; hub->space->dir.y = -1;
	/* Win_size */ hub->draw->win_size[0] = WIN_X; hub->draw->win_size[1] = WIN_Y;
	return (1);
}
