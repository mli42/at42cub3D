/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_moves_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2020/01/28 16:56:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_w_key(t_hub *hub)
{
	hub->player->entity.pos.y += (hub->player->entity.dir.y *
									hub->player->entity.speed * 2.5);
	hub->player->entity.pos.x += (hub->player->entity.dir.x *
									hub->player->entity.speed * 2.5);
}

void	ft_s_key(t_hub *hub)
{
	hub->player->entity.pos.y -= (hub->player->entity.dir.y *
									hub->player->entity.speed * 2.5);
	hub->player->entity.pos.x -= (hub->player->entity.dir.x *
									hub->player->entity.speed * 2.5);
}

void	ft_a_key(t_hub *hub)
{
	double	turn;
	t_coord	left_side;

	turn = atan2(hub->player->entity.dir.y, hub->player->entity.dir.x) - RAD_90;
	left_side.x = cos(turn);
	left_side.y = sin(turn);
	hub->player->entity.pos.y += (left_side.y * hub->player->entity.speed);
	hub->player->entity.pos.x += (left_side.x * hub->player->entity.speed);
}

void	ft_d_key(t_hub *hub)
{
	double	turn;
	t_coord	right_side;

	turn = atan2(hub->player->entity.dir.y, hub->player->entity.dir.x) + RAD_90;
	right_side.x = cos(turn);
	right_side.y = sin(turn);
	hub->player->entity.pos.y += (right_side.y * hub->player->entity.speed);
	hub->player->entity.pos.x += (right_side.x * hub->player->entity.speed);
}
