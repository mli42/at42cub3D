/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/01/26 18:30:26 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_is_close(int **map, int max_x, int max_y)
{
	int i;

	i = -1;
	while (++i < max_y)
		if (map[i][0] != 1 || map[i][max_x - 1] != 1)
			return (0);
	i = -1;
	while (++i < max_x)
		if (map[0][i] != 1 || map[max_y - 1][i] != 1)
			return (0);
	return (1);
}

int		ft_only_one_pos(t_hub *hub, int dir, int i, int j)
{
	static int pass = 0;

	hub->player->entity.pos.x = (float)j - 0.5;
	hub->player->entity.pos.y = (float)i - 0.5;
	if (dir == 'N')
	{
		hub->player->entity.dir.x = 0;
		hub->player->entity.dir.y = -1;
	}
	else if (dir == 'S')
	{
		hub->player->entity.dir.x = 0;
		hub->player->entity.dir.y = 1;
	}
	else if (dir == 'E')
	{
		hub->player->entity.dir.x = 1;
		hub->player->entity.dir.y = 0;
	}
	else
	{
		hub->player->entity.dir.x = -1;
		hub->player->entity.dir.y = 0;
	}
	return ((++pass == 1 ? 1 : 0));
}

int		ft_pos_map(t_hub *hub, int **map, int max_x, int max_y)
{
	int i;
	int j;
	int pass;

	i = 0;
	pass = 0;
	while (++i < max_y - 1)
	{
		j = 0;
		while (++j < max_x - 1)
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
					map[i][j] == 'W' || map[i][j] == 'E')
				if (++pass && ft_only_one_pos(hub, map[i][j], i, j) == 0)
					return (0);
	}
	if (pass != 1)
		return (0);
	return (1);
}

int		ft_is_map_good(t_hub *hub)
{
	int **map;
	int max[2];

	map = hub->env->map;
	max[0] = hub->env->map_width;
	max[1] = hub->env->map_height;
	if (ft_is_close(map, max[0], max[1]) == 0)
		return (-1);
	if (ft_pos_map(hub, map, max[0], max[1]) == 0)
		return (-1);
	return (1);
}
