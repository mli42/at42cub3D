/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:45:26 by mli               #+#    #+#             */
/*   Updated: 2020/03/04 17:08:16 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_switch_all_opt_state(t_hub *hub, char state)
{
	int i;

	i = -1;
	while (++i < e_nb_options)
		hub->options[i] = state;
	hub->player->collision = state;
	hub->player->entity.speed = (state ? FOOT_STEP * BIG_FOOT : FOOT_STEP);
}

void	ft_activate_all_opt(t_hub *hub)
{
	ft_switch_all_opt_state(hub, 1);
}

void	ft_sprite_state(t_hub *hub)
{
	hub->options[e_sprite]++;
	if (hub->options[e_sprite] == e_sp_limit)
		hub->options[e_sprite] = e_sp_nothing;
}
