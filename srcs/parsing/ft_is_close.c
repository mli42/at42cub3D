/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/03/18 14:50:55 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_iswalkable(char c)
{
	if (ft_isposition(c) || c == 0 || c == 2)
		return (1);
	return (0);
}

int		is_outside_border(t_hub *hub, int i, int j)
{
	if (i < 0 || j < 0 || j >= hub->env->full_height ||
			i >= hub->env->width[j].border[1])
		return (1);
	return (0);
}

int		good_borders(t_hub *hub, int **map, t_limit *border_x, int full_height)
{
	int i;
	int j;

	i = -1;
	while (++i < full_height)
		if (!ft_iswallspace(map[i][0]) ||
			!ft_iswallspace(map[i][border_x[i].border[1] - 1]))
			return (0);
	j = -1;
	while (++j < full_height)
	{
		i = -1;
		while (++i < border_x[j].border[1])
			if (is_outside_border(hub, i, j - 1) ||
				is_outside_border(hub, i, j + 1))
				if (!ft_iswallspace(map[j][i]))
					return (0);
	}
	return (1);
}

int		ft_neighbour_ok(t_hub *hub, int **map, int x, int y)
{
	if (!is_outside_border(hub, x, y) && map[y][x] == ' ')
		return (0);
	return (1);
}

int		ft_is_close(t_hub *hub, int **map, t_limit *border_x, int full_height)
{
	int j;
	int i;

	if (!good_borders(hub, map, border_x, full_height))
		return (0);
	j = -1;
	while (++j < full_height)
	{
		i = -1;
		while (++i < border_x[j].border[1])
			if (ft_iswalkable(map[j][i]))
				if (!ft_neighbour_ok(hub, map, i, j - 1) ||
					!ft_neighbour_ok(hub, map, i, j + 1) ||
					!ft_neighbour_ok(hub, map, i - 1, j) ||
					!ft_neighbour_ok(hub, map, i + 1, j) ||
					!ft_neighbour_ok(hub, map, i - 1, j - 1) ||
					!ft_neighbour_ok(hub, map, i + 1, j - 1) ||
					!ft_neighbour_ok(hub, map, i - 1, j + 1) ||
					!ft_neighbour_ok(hub, map, i + 1, j + 1))
					return (0);
	}
	return (1);
}
