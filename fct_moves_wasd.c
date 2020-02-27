/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_moves_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2020/02/27 17:50:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_w_key(t_hub *hub)
{
	t_coord		zukunft;
	t_entity	entity;

	entity = hub->player->entity;
	zukunft.y = entity.pos.y + (entity.dir.y * entity.speed * 2.5);
	zukunft.x = entity.pos.x + (entity.dir.x * entity.speed * 2.5);
	if (!hub->player->collision || !map_is_what(hub, zukunft, 1))
	{
		hub->player->entity.pos.y = zukunft.y;
		hub->player->entity.pos.x = zukunft.x;
	}
	else
	{
		if (hub->env->map[(int)zukunft.y][(int)entity.pos.x] != 1)
			hub->player->entity.pos.y = zukunft.y;
		if (hub->env->map[(int)entity.pos.y][(int)zukunft.x] != 1)
			hub->player->entity.pos.x = zukunft.x;
	}
}

void	ft_s_key(t_hub *hub)
{
	t_coord		zukunft;
	t_entity	entity;

	entity = hub->player->entity;
	zukunft.y = entity.pos.y - (entity.dir.y * entity.speed * 2.5);
	zukunft.x = entity.pos.x - (entity.dir.x * entity.speed * 2.5);
	if (!hub->player->collision || !map_is_what(hub, zukunft, 1))
	{
		hub->player->entity.pos.y = zukunft.y;
		hub->player->entity.pos.x = zukunft.x;
	}
	else
	{
		if (hub->env->map[(int)zukunft.y][(int)entity.pos.x] != 1)
			hub->player->entity.pos.y = zukunft.y;
		if (hub->env->map[(int)entity.pos.y][(int)zukunft.x] != 1)
			hub->player->entity.pos.x = zukunft.x;
	}
}

void	ft_a_key(t_hub *hub)
{
	double		turn;
	t_coord		then;
	t_entity	entity;

	entity = hub->player->entity;
	turn = atan2(entity.dir.y, entity.dir.x) - RAD_90;
	then.x = entity.pos.x + cos(turn) * entity.speed;
	then.y = entity.pos.y + sin(turn) * entity.speed;
	if (!hub->player->collision || !map_is_what(hub, then, 1))
	{
		hub->player->entity.pos.y = then.y;
		hub->player->entity.pos.x = then.x;
	}
	else
	{
		if (hub->env->map[(int)then.y][(int)entity.pos.x] != 1)
			hub->player->entity.pos.y = then.y;
		if (hub->env->map[(int)entity.pos.y][(int)then.x] != 1)
			hub->player->entity.pos.x = then.x;
	}
}

void	ft_d_key(t_hub *hub)
{
	double		turn;
	t_coord		then;
	t_entity	entity;

	entity = hub->player->entity;
	turn = atan2(entity.dir.y, entity.dir.x) + RAD_90;
	then.x = entity.pos.x + cos(turn) * entity.speed;
	then.y = entity.pos.y + sin(turn) * entity.speed;
	if (!hub->player->collision || !map_is_what(hub, then, 1))
	{
		hub->player->entity.pos.y = then.y;
		hub->player->entity.pos.x = then.x;
	}
	else
	{
		if (hub->env->map[(int)then.y][(int)entity.pos.x] != 1)
			hub->player->entity.pos.y = then.y;
		if (hub->env->map[(int)entity.pos.y][(int)then.x] != 1)
			hub->player->entity.pos.x = then.x;
	}
}
