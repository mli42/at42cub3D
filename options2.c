/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:45:26 by mli               #+#    #+#             */
/*   Updated: 2020/03/05 14:52:37 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./disp_sprites/ft_affine.h"

void	ft_draw_one_case(t_hub *hub, int size[2], t_icoord win, int color)
{
	int k;
	int l;

	k = -1;
	while (++k < size[1])
	{
		l = -1;
		while (++l < size[0])
			hub->win->img_data[(l + size[0] * (win.x + 1)) +
		(k + size[1] * (win.y + 1)) * hub->win->win_size[0]] = color;
	}
}

void	ft_minimap(t_hub *hub, int **map, t_limit *width, int height)
{
	int			size[2];
	t_icoord	in_map;

	in_map.y = -1;
	size[0] = hub->win->win_size[0] * 6 / 1440;
	size[1] = hub->win->win_size[1] * 7 / 900;
	while (++in_map.y < height)
	{
		in_map.x = width[in_map.y].border[0];
		while (++in_map.x < width[in_map.y].border[1])
		{
			if (same_pos(hub->player->entity.pos,
									(t_coord){in_map.x, in_map.y}))
				ft_draw_one_case(hub, size, in_map, YELLOW);
			else if (map[in_map.y][in_map.x] == 1)
				ft_draw_one_case(hub, size, in_map, 0);
			else if (map[in_map.y][in_map.x] == 2)
				ft_draw_one_case(hub, size, in_map, ORANGE);
			else if (map[in_map.y][in_map.x] != ' ')
				ft_draw_one_case(hub, size, in_map, GREY_FLOOR);
		}
	}
}

void	in_game(t_hub *hub)
{
	if ((hub->options[e_sprite] == e_sp_eatable) &&
			!is_outside_map(hub, hub->player->entity.pos) &&
			map_is_what(hub, hub->player->entity.pos, 2))
	{
		hub->player->entity.life -= 10;
		hub->env->map[(int)hub->player->entity.pos.y]
					[(int)hub->player->entity.pos.x] = 'T';
	}
	if (hub->player->entity.life <= 0)
	{
		ft_putstr("\n\tYOU DIED.\n\n");
		exit(ft_remove_all(hub));
	}
	if (hub->options[e_sprite] == e_sp_eatable)
		ft_life(hub);
	if (hub->options[e_minimap])
		ft_minimap(hub, hub->env->map, hub->env->width, hub->env->full_height);
}
