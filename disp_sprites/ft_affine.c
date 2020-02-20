/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/02/20 13:39:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_points_dist(t_coord a, t_coord b)
{
	return (hypot(b.x - a.x, b.y - a.y));
}

double	ft_dist_to_sp(t_coord my_pos, t_coord sp_pos)
{
	sp_pos.x = (int)sp_pos.x + 0.5;
	sp_pos.y = (int)sp_pos.y + 0.5;
	return (ft_points_dist(my_pos, sp_pos));
}

int		same_pos(t_coord a, t_coord b)
{
	if (((int)a.x) == ((int)b.x) && ((int)a.y) == (int)b.y)
		return (1);
	return (0);
}

double	ft_sp_offset(t_sp sprite, double ray)
{
	(void)sprite;
	(void)ray;
	return (0);
}

double		ft_find_b(t_coord a, double ax)
{
	return (a.x / ax + a.y);
}

t_faffine	ft_dirf(t_coord a, t_coord b)
{
	t_faffine dir;

	dir.a = (b.y - a.y) / (b.x - a.x);
	dir.b = ft_find_b(a, dir.a);
	return (dir);
}

t_faffine	ft_perpf(t_faffine dir, t_coord point)
{
	t_faffine perp;

	perp.a = -(1 / dir.a);
	perp.b = ft_find_b(point, perp.a);
	return (perp);
}
