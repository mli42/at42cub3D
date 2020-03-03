/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/03/03 16:43:42 by mli              ###   ########.fr       */
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

double		ft_sp_offset(t_hub *hub, t_sp sprite)
{
	double angle;

	angle = asin(((sprite.center.x - hub->player->entity.pos.x) *
		-sin(sprite.ray) + (sprite.center.y - hub->player->entity.pos.y) *
		cos(sprite.ray)) / sprite.distance);
	return (.5 + sprite.distance * tan(angle));
}
