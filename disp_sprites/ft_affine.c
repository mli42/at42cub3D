/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 16:55:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

int			same_pos(t_coord a, t_coord b)
{
	if (((int)a.x) == ((int)b.x) && ((int)a.y) == (int)b.y)
		return (1);
	return (0);
}

double		ft_find_x(t_faffine fct, double y)
{
	return ((y - fct.b) / fct.a);
}

double		ft_find_b(t_coord a, double ax)
{
	return (a.y - a.x * ax);
}

double		ft_affine(t_faffine fct, double x)
{
	return (fct.a * x + fct.b);
}

double		ft_sp_offset(t_sp sprite, t_faffine perp, t_coord m)
{
	t_coord	a;
	t_coord	b;

	if (sprite.face == 'N' || sprite.face == 'S')
	{
		a.x = (int)m.x;
		a.y = ft_affine(perp, a.x);
		b.x = (int)m.x + 1;
		b.y = ft_affine(perp, b.x);
	}
	else
	{
		a.y = (int)m.y;
		a.x = ft_find_x(perp, a.y);
		b.y = (int)m.y + 1;
		b.x = ft_find_x(perp, b.y);
	}
	return (ft_points_dist(a, m) / ft_points_dist(a, b));
}
