/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_do_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:52:51 by mli               #+#    #+#             */
/*   Updated: 2020/02/28 16:55:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_coord	v_add(t_coord a, t_coord b)
{
	t_coord	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_coord	v_sub(t_coord a, t_coord b)
{
	t_coord	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return (c);
}

t_coord	v_scal(t_coord a, double b)
{
	t_coord c;

	c.x = a.x * b;
	c.y = a.y * b;
	return (c);
}
