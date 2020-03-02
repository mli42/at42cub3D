/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:41:27 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 16:44:58 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

void	can_see_sprite(t_hub *hub, t_coord pt)
{
	int k;

	k = -1;
	while (++k < hub->env->sp_nb)
	{
		if (same_pos(pt, hub->env->sp[k].center))
		{
			hub->env->sp[k].can_see = 1;
			break ;
		}
	}
}

void	sprite_2(t_hub *hub, t_coord here)
{
	int k;

	k = -1;
	if (same_pos(here, hub->player->entity.pos))
		while (++k < hub->env->sp_nb)
			if (hub->env->sp[k].can_see)
			{
				hub->env->sp[k].distance = ft_points_dist(
						hub->player->entity.pos, hub->env->sp[k].center);
				ft_sprite_next(hub, hub->env->sp[k]);
			}
}
