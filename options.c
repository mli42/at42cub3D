/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:28:28 by mli               #+#    #+#             */
/*   Updated: 2020/01/30 00:43:38 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_speed(t_hub *hub)
{
	hub->player->entity.speed = (hub->player->entity.speed >= FOOT_STEP ?
			FOOT_STEP : FOOT_STEP * 2.3);
}

void	ft_life(t_hub *hub)
{
	int x;
	int y;
	int bar_len;
	int bar_size[2];
	static float color = 0xFFFFFF;

	bar_len = (hub->win->win_size[0] - (hub->win->win_size[0] * 0.7)) / 2;
	bar_size[0] = hub->win->win_size[1] >> 5;
	bar_size[1] = bar_size[0] + hub->win->win_size[1] * 0.02;

	y = -1;
	if (color >= 134217728)
		color = 0xFFFFFF;
	while (++y < hub->win->win_size[1])
	{
		x = -1;
		while (++x < hub->win->win_size[0])
		{
			if ((x > bar_len && x < hub->win->win_size[0] - bar_len) &&
					y > bar_size[0] && y < bar_size[1])
			{
				hub->win->img_data[y * hub->win->win_size[0] + x] = (int)color;
				color += 3;
			}
		}
	}
}
