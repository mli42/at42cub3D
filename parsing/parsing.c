/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/01/03 23:36:52 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_first_vars(t_param *hub, t_ref ref_parse, int fd)
{
	int		i;
	int		k;
	int		gnl_value;
	char	*line;

	i = 0;
	while ((gnl_value = get_next_line(fd, &line)) == 1 && !line[0])
		;
	ft_pass_spaces(line, &i);
	while (gnl_value == 1 && line[i] != '1')
	{
		k = 0;
		while (k < 3 && ft_strncmp(&line[i], ref_parse.ref[k], 1))
			k++;
		gnl_value = (k < 3 ? ref_parse.f_ref[k](hub, &line[i]) : -1);
		ft_free((void **)&line);
		i = 0;
		if (gnl_value == 1)
			while ((gnl_value = get_next_line(fd, &line)) == 1 && !line[0])
				;
		ft_pass_spaces(line, &i);
	}
	if (gnl_value != 1)
		get_next_line(-1, NULL);
	return (gnl_value == 1 ? 1 : ft_error("Map Reference Error", hub));
}

int			ft_parse(t_param *hub, char *filename)
{
	int			fd;

	if ((fd = ft_good_name(filename)) == -1)
		return (ft_error("Given file not correct", hub));
	if (ft_first_vars(hub, ft_ref_parse(), fd) == -1)
		return (-1);
	// Check if every ref has been called


	/* Being at the center */ hub->space->pos.x = 3.5; hub->space->pos.y = 3.5;
	/* Watching North */ hub->space->dir.x = 0; hub->space->dir.y = -1;
	/* Win_size */ hub->draw->win_size[0] = WIN_X; hub->draw->win_size[1] = WIN_Y;
	return (1);
}
