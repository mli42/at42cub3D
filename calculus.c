/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:00:25 by mli               #+#    #+#             */
/*   Updated: 2020/01/28 16:56:06 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_recalculate_povs(t_player *player)
{
	player->entity.dir_rad = atan2(player->entity.dir.y, player->entity.dir.x);
	player->pov_min.x = cos(player->entity.dir_rad + RAD_30);
	player->pov_min.y = sin(player->entity.dir_rad + RAD_30);
	player->pov_min_rad = atan2(player->pov_min.y, player->pov_min.x);
//	if (player->pov_min_rad < 0)
//		player->pov_min_rad += PI2;
	player->pov_max.x = cos(player->entity.dir_rad - RAD_30);
	player->pov_max.y = sin(player->entity.dir_rad - RAD_30);
	player->pov_max_rad = atan2(player->pov_max.y, player->pov_max.x);
//	if (player->pov_max_rad < 0)
//		player->pov_max_rad += PI2;
}
