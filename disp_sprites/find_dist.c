/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:52:51 by mli               #+#    #+#             */
/*   Updated: 2020/03/03 16:00:32 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

double	ft_points_dist(t_coord a, t_coord b)
{
	return (hypot(b.x - a.x, b.y - a.y));
}

double	ft_dist_to_sp(t_coord my_pos, t_coord sp_pos)
{
	sp_pos.x = (int)sp_pos.x + 0.500001;
	sp_pos.y = (int)sp_pos.y + 0.500001;
	return (ft_points_dist(my_pos, sp_pos));
}
