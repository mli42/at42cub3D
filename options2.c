/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:45:26 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 14:10:15 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	in_game(t_hub *hub)
{
	if (!hub->player->collision)
		return ;
	if (!is_outside_map(hub, hub->player->entity.pos) &&
			map_is_what(hub, hub->player->entity.pos, 2))
	{
		hub->player->entity.life -= 10;
		hub->env->map[(int)hub->player->entity.pos.y]
					[(int)hub->player->entity.pos.x] = 'T';
	}
	if (hub->player->entity.life <= 0)
	{
		ft_putstr("YOU DIED.\n");
		exit(ft_remove_all(hub));
	}
}
