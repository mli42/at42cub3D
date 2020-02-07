/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/02/07 16:29:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map(t_hub *hub)
{
	int i = -1;
	int j = -1;
	int **map = hub->env->map;

	while (++i < hub->env->map_height)
	{
		j = -1;
		while (++j < hub->env->map_width[i])
		{
			if (ft_isdigit(map[i][j] + 48))
				ft_putnbr(map[i][j]);
			else
				ft_putchar(map[i][j]);
		}
		ft_putchar('\n');
	}
}

int		ft_is_close(int **map, int *max_tab, int max_y)
{
	int i;
	int max_x;
	int prev;

	i = -1;
	max_x = max_tab[0];
	while (++i < max_x)
	{
		if (map[0][i] != 1)
			return (0);
//		map[0][i] = 'A';
	}
	i = -1;
	max_x = max_tab[max_y - 1];
	while (++i < max_x)
	{
		if (map[max_y - 1][i] != 1)
			return (0);
//		map[max_y - 1][i] = 'B';
	}
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
	int **map;

	map = hub->env->map;
	if (ft_is_close(map, hub->env->map_width, hub->env->map_height) == 0)
	{
		print_map(hub);
		return (-1);
	}
	if (ft_pos_map(hub, map, hub->env->map_width, hub->env->map_height) == 0)
		return (-1);
	return (1);
}
