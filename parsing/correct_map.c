/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/02/28 14:59:03 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_h_border(int **map, int max_x, int line_n)
{
	int i;

	i = -1;
	while (++i < max_x)
		if (map[line_n][i] != 1)
			return (0);
	return (1);
}

int		ft_is_close(int **map, int *max_tab, int max_y)
{
	int i;
	int max_x;
	int prev;

	if (!ft_h_border(map, max_tab[0], 0) ||
		!ft_h_border(map, max_tab[max_y - 1], max_y - 1))
		return (0);
	i = 0;
	while (++i < max_y)
	{
		prev = max_tab[i - 1];
		max_x = max_tab[i];
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

	hub->player->entity.pos.x = (float)j - 0.5;
	hub->player->entity.pos.y = (float)i - 0.5;
	if (dir == 'N')
	{
		hub->player->entity.dir = (t_coord){0, -1};
		hub->plane = (t_coord){.66, 0};
	}
	else if (dir == 'S')
	{
		hub->player->entity.dir = (t_coord){0, 1};
		hub->plane = (t_coord){-.66, 0};
	}
	else if (dir == 'E')
	{
		hub->player->entity.dir = (t_coord){1, 0};
		hub->plane = (t_coord){0, .66};
	}
	else
	{
		hub->player->entity.dir = (t_coord){-1, 0};
		hub->plane = (t_coord){0, -.66};
	}
	return ((++pass == 1 ? 1 : 0));
}

int		ft_pos_map(t_hub *hub, int **map, int *max_tab, int max_y)
{
	int i;
	int j;
	int pass;
	int max_x;

	i = 0;
	pass = 0;
	while (++i < max_y - 1)
	{
		j = 0;
		max_x = max_tab[i];
		while (++j < max_x - 1)
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
					map[i][j] == 'W' || map[i][j] == 'E')
				if (++pass != 1 || ft_only_one_pos(hub, map[i][j], i, j) == 0)
					return (0);
	}
	return (1);
}

int		ft_is_map_good(t_hub *hub)
{
	if (!ft_is_close(hub->env->map, hub->env->map_width, hub->env->map_height)
	|| (!ft_pos_map(hub, hub->env->map,
			hub->env->map_width, hub->env->map_height)))
		return (-1);
	return (1);
}
