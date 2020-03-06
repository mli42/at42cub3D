/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/03/06 14:23:01 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_iswalkable(char c)
{
	if (ft_isposition(c) || c == 0 || c == 2)
		return (1);
	return (0);
}

int		ft_h_border(t_hub *hub, int **map, int row)
{
	int i;

	i = -1;
	while (++i < hub->env->width[row].border[1])
		if (!ft_iswallspace(map[row][i]))
			return (0);
	return (1);
}

int		good_borders(t_hub *hub, int **map, t_limit *border_x, int full_height)
{
	int i;

	i = -1;
	while (++i < full_height)
		if (!ft_iswallspace(map[i][0]))
			return (0);
	if (!ft_h_border(hub, map, 0) || !ft_h_border(hub, map, full_height - 1))
		return (0);
	i = 0;
	while (++i < full_height)
		if (!ft_iswallspace(map[i][border_x[i].border[1] - 1]))
			return (0);
	return (1);
}

int		ft_check_walkable(t_hub *hub, int i, int j)
{
	if (!is_outside_map(hub, (t_coord){i, j - 1}) &&
			hub->env->map[j - 1][i] == ' ')
		return (0);
	if (!is_outside_map(hub, (t_coord){i, j + 1}) &&
			hub->env->map[j + 1][i] == ' ')
		return (0);
	if (!is_outside_map(hub, (t_coord){i - 1, j}) &&
			hub->env->map[j][i - 1] == ' ')
		return (0);
	if (!is_outside_map(hub, (t_coord){i + 1, j}) &&
			hub->env->map[j][i + 1] == ' ')
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
				if (ft_check_walkable(hub, i, j) == 0)
					return (0);
	}
	return (1);
}
