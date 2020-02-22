/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/02/22 17:57:02 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double		ft_points_dist(t_coord a, t_coord b)
{
	return (hypot(b.x - a.x, b.y - a.y));
}

double		ft_dist_to_sp(t_coord my_pos, t_coord sp_pos)
{
	sp_pos.x = (int)sp_pos.x + 0.500001;
	sp_pos.y = (int)sp_pos.y + 0.500001;
	return (ft_points_dist(my_pos, sp_pos));
}

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

double      ft_sp_offset(t_sp sprite, t_faffine perp, t_coord m)
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

t_faffine	ft_castf(double ray, t_coord a)
{
	t_faffine	cast;

	cast.a = sin(ray) / cos(ray);
	cast.b = a.y - (a.x * cast.a);
	return (cast);
}

t_coord		resolve_eq(t_faffine one, t_faffine two)
{
	t_coord res;

	res.x = (two.b - one.b) / (one.a - two.a);
	res.y = ft_affine(one, res.x);
	return (res);
}
