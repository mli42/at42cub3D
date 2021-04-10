/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_moves_wasd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2020/03/04 22:42:12 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_can_move(t_hub *hub, t_coord then, char w_s)
{
	if (w_s == 1)
		if (!hub->player->collision || (!is_outside_map(hub, then) &&
			!map_is_what(hub, then, 1)))
			return (1);
	if (w_s == 2)
		if ((hub->options[e_sprite] != e_sp_collision) || (is_outside_map(hub,
			then) || !map_is_what(hub, then, 2)))
			return (1);
	return (0);
}

void	ft_w_key(t_hub *hub)
{
	t_coord		zukunft;
	t_entity	entity;

	entity = hub->player->entity;
	zukunft.y = entity.pos.y + (entity.dir.y * entity.speed * 2.5);
	zukunft.x = entity.pos.x + (entity.dir.x * entity.speed * 2.5);
	if (!hub->player->collision && hub->options[e_sprite] != e_sp_collision)
		hub->player->entity.pos = zukunft;
	else
	{
		if (ft_can_move(hub, (t_coord){entity.pos.x, zukunft.y}, 1) &&
			ft_can_move(hub, (t_coord){entity.pos.x, zukunft.y}, 2))
			hub->player->entity.pos.y = zukunft.y;
		if (ft_can_move(hub, (t_coord){zukunft.x, entity.pos.y}, 1) &&
			ft_can_move(hub, (t_coord){zukunft.x, entity.pos.y}, 2))
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
	if (!hub->player->collision && hub->options[e_sprite] != e_sp_collision)
		hub->player->entity.pos = zukunft;
	else
	{
		if (ft_can_move(hub, (t_coord){entity.pos.x, zukunft.y}, 1) &&
			ft_can_move(hub, (t_coord){entity.pos.x, zukunft.y}, 2))
			hub->player->entity.pos.y = zukunft.y;
		if (ft_can_move(hub, (t_coord){zukunft.x, entity.pos.y}, 1) &&
			ft_can_move(hub, (t_coord){zukunft.x, entity.pos.y}, 2))
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
	if (!hub->player->collision && hub->options[e_sprite] != e_sp_collision)
		hub->player->entity.pos = then;
	else
	{
		if (ft_can_move(hub, (t_coord){entity.pos.x, then.y}, 1) &&
			ft_can_move(hub, (t_coord){entity.pos.x, then.y}, 2))
			hub->player->entity.pos.y = then.y;
		if (ft_can_move(hub, (t_coord){then.x, entity.pos.y}, 1) &&
			ft_can_move(hub, (t_coord){then.x, entity.pos.y}, 2))
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
	if (!hub->player->collision && hub->options[e_sprite] != e_sp_collision)
		hub->player->entity.pos = then;
	else
	{
		if (ft_can_move(hub, (t_coord){entity.pos.x, then.y}, 1) &&
			ft_can_move(hub, (t_coord){entity.pos.x, then.y}, 2))
			hub->player->entity.pos.y = then.y;
		if (ft_can_move(hub, (t_coord){then.x, entity.pos.y}, 1) &&
			ft_can_move(hub, (t_coord){then.x, entity.pos.y}, 2))
			hub->player->entity.pos.x = then.x;
	}
}
