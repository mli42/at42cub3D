/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/01/02 01:24:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_parsing	*parse;

	parse = hub->parse;
	if ((fd = ft_good_name(filename)) == -1)
		return (ft_error("Given file not correct", hub));

	/* Being at the center */ hub->space->pos.x = 3.5; hub->space->pos.y = 3.5;
	/* Watching North */ hub->space->dir.x = 0; hub->space->dir.y = -1;
	/* Win_size */ hub->draw->win_size[0] = WIN_X; hub->draw->win_size[1] = WIN_Y;
	return (1);
}
