/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 16:56:16 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

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
