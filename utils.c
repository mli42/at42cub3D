/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:00:03 by mli               #+#    #+#             */
/*   Updated: 2020/02/02 23:15:43 by mli              ###   ########.fr       */
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
