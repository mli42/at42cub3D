/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/03/05 16:34:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_is_close(int **map, t_limit *border_x, int max_y)
{
	int i;
	int max_x;
	int prev;

	i = 0;
	while (++i < max_y)
	{
		prev = border_x[i - 1].border[1];
		max_x = border_x[i].border[1];
		while (prev < max_x)
			if (map[i][--max_x - 1] != 1)
				return (0);
		while (prev >= max_x)
			if (map[i - 1][--prev] != 1)
				return (0);
	}
	return (1);
}

int		ft_only_one_pos(t_hub *hub, int dir, int i, int j)
{
	static int pass = 0;

	hub->player->entity.pos.x = (float)j + 0.5;
	hub->player->entity.pos.y = (float)i + 0.5;
	if (dir == 'N')
		hub->player->entity.dir = (t_coord){0, -1};
	else if (dir == 'S')
		hub->player->entity.dir = (t_coord){0, 1};
	else if (dir == 'E')
		hub->player->entity.dir = (t_coord){1, 0};
	else
		hub->player->entity.dir = (t_coord){-1, 0};
	return ((++pass == 1 ? 1 : 0));
}

int		ft_pos_map(t_hub *hub, int **map, t_limit *border_x, int max_y)
{
	int i;
	int j;
	int pass;
	int max_x;

	i = 0;
	pass = 0;
	while (++i < max_y - 1)
	{
		j = border_x[i].border[0];
		max_x = border_x[i].border[1] - 1;
		while (++j < max_x)
			if (ft_isposition(map[i][j]))
				if (++pass != 1 || ft_only_one_pos(hub, map[i][j], i, j) == 0)
					return (0);
	}
	return (1);
}

int		ft_is_map_good(t_hub *hub)
{
//	if (!ft_is_close(hub->env->map, hub->env->width, hub->env->full_height)
//	|| !ft_pos_map(hub, hub->env->map, hub->env->width, hub->env->full_height))
//		return (-1);
	ft_pos_map(hub, hub->env->map, hub->env->width, hub->env->full_height);
	return (1);
}
