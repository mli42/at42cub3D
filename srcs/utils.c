/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:00:03 by mli               #+#    #+#             */
/*   Updated: 2020/03/06 14:21:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_abs_double(double nbr)
{
	return ((nbr >= 0 ? nbr : -nbr));
}

t_walls	ft_walls(int face, double distance, t_coord check_pt)
{
	t_walls walls;

	walls.face = face;
	walls.distance = distance;
	walls.check_pt = check_pt;
	return (walls);
}

int		map_is_what(t_hub *hub, t_coord cmp, int nb)
{
	if (hub->env->map[(int)cmp.y][(int)cmp.x] == nb)
		return (1);
	return (0);
}

int		is_outside_map(t_hub *hub, t_coord pt)
{
	if (pt.x <= 0 || pt.y <= 0 || pt.y >= hub->env->full_height - 1 ||
			pt.x >= hub->env->width[(int)pt.y].border[1] - 1)
		return (1);
	return (0);
}

int		ft_iswallspace(char c)
{
	if (c == 1 || c == ' ')
		return (1);
	return (0);
}
