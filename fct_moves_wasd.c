/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_moves_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2020/01/30 15:37:28 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_w_key(t_hub *hub)
{
	t_coord zukunft;

	zukunft.y = hub->player->entity.pos.y +
		(hub->player->entity.dir.y * hub->player->entity.speed * 2.5);
	zukunft.x = hub->player->entity.pos.x +
		(hub->player->entity.dir.x * hub->player->entity.speed * 2.5);
	if (!hub->player->collision ||
			hub->env->map[(int)zukunft.y + 1][(int)zukunft.x + 1] != 1)
	{
		hub->player->entity.pos.y = zukunft.y;
		hub->player->entity.pos.x = zukunft.x;
	}
}

void	ft_s_key(t_hub *hub)
{
	t_coord zukunft;

	zukunft.y = hub->player->entity.pos.y -
		(hub->player->entity.dir.y * hub->player->entity.speed * 2.5);
	zukunft.x = hub->player->entity.pos.x -
		(hub->player->entity.dir.x * hub->player->entity.speed * 2.5);
	if (!hub->player->collision ||
			hub->env->map[(int)zukunft.y + 1][(int)zukunft.x + 1] != 1)
	{
		hub->player->entity.pos.y = zukunft.y;
		hub->player->entity.pos.x = zukunft.x;
	}
}

void	ft_a_key(t_hub *hub)
{
	double	turn;
	t_coord	then;

	turn = atan2(hub->player->entity.dir.y, hub->player->entity.dir.x) - RAD_90;
	then.x = hub->player->entity.pos.x + cos(turn) * hub->player->entity.speed;
	then.y = hub->player->entity.pos.y + sin(turn) * hub->player->entity.speed;
	if (!hub->player->collision ||
			hub->env->map[(int)then.y + 1][(int)then.x + 1] != 1)
	{
		hub->player->entity.pos.y = then.y;
		hub->player->entity.pos.x = then.x;
	}
}

void	ft_d_key(t_hub *hub)
{
	double	turn;
	t_coord	then;

	turn = atan2(hub->player->entity.dir.y, hub->player->entity.dir.x) + RAD_90;
	then.x = hub->player->entity.pos.x + cos(turn) * hub->player->entity.speed;
	then.y = hub->player->entity.pos.y + sin(turn) * hub->player->entity.speed;
	if (!hub->player->collision ||
			hub->env->map[(int)then.y + 1][(int)then.x + 1] != 1)
	{
		hub->player->entity.pos.y = then.y;
		hub->player->entity.pos.x = then.x;
	}
}
