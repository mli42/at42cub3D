/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/03/06 12:59:59 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_iswallspace(char c)
{
	if (c == 1 || c == ' ')
		return (1);
	return (0);
}

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

int		ft_is_close(t_hub *hub, int **map, t_limit *border_x, int full_height)
{
	if (!good_borders(hub, map, border_x, full_height))
		return (0);
	return (1);
}
