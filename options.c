/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:28:28 by mli               #+#    #+#             */
/*   Updated: 2020/01/30 15:55:19 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_speed(t_hub *hub)
{
	hub->player->entity.speed = (hub->player->entity.speed >= FOOT_STEP ?
			FOOT_STEP : FOOT_STEP * 2.3);
}

static void	ft_drawbar(t_hub *hub, int bar_max[2], int x, int y)
{
	int				border;
	int				start[2];
	static float	color = 0xFFFFFF;

	start[0] = x;
	start[1] = y;
	border = (bar_max[1] - start[1]) * 0.45;
	if (color >= 67108864)
		color = 0xFFFFFF;
	while (++y < bar_max[1])
	{
		x = start[0];
		while (++x < bar_max[0])
		{
			if (x < start[0] + border || x > bar_max[0] - border ||
					y < start[1] + border || y > bar_max[1] - border)
				hub->win->img_data[y * hub->win->win_size[0] + x] = 0xFFFFFF;
			else if (x - start[0] > (bar_max[0] - start[0])
					* hub->player->entity.life / 100)
				hub->win->img_data[y * hub->win->win_size[0] + x] = 0;
			else
				hub->win->img_data[y * hub->win->win_size[0] + x] = (int)color;
			color += 3;
		}
	}
}

void		ft_life(t_hub *hub)
{
	int bar_begin[2];
	int bar_max[2];

	bar_begin[0] = (hub->win->win_size[0] - (hub->win->win_size[0] * 0.7)) / 2;
	bar_begin[1] = hub->win->win_size[1] >> 5;
	bar_max[0] = hub->win->win_size[0] - bar_begin[0];
	bar_max[1] = bar_begin[1] + hub->win->win_size[1] * 0.02;
	ft_drawbar(hub, bar_max, bar_begin[0] - 1, bar_begin[1] - 1);
}

void		ft_collision(t_hub *hub)
{
	hub->player->collision = (hub->player->collision == 1 ? 0 : 1);
}
