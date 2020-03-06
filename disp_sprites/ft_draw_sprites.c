/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/03/06 14:12:58 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

double	ft_points_dist(t_coord a, t_coord b)
{
	return (hypot(b.x - a.x, b.y - a.y));
}

t_sp	ft_sprites(t_hub *hub, t_coord pos, double ray)
{
	t_sp sprite;

	sprite.ray = ray;
	sprite.center = (t_coord){(int)pos.x + 0.500001, (int)pos.y + 0.500001};
	sprite.distance = ft_points_dist(hub->player->entity.pos, sprite.center);
	sprite.offset = ft_sp_offset(hub, sprite);
	return (sprite);
}

int		ft_sp_color(t_data texture, t_sp sprite, float y)
{
	return (texture.data[(int)(((int)y) * texture.height +
				(1 - sprite.offset) * texture.width)]);
}

void	ft_draw_sp_ray(t_hub *hub, int i, t_sp sprite, t_data texture)
{
	int		x;
	float	y;
	int		pixel;
	int		padding_limit;

	if (sprite.offset <= 0 || sprite.offset >= 1)
		return ;
	x = -1;
	y = -1;
	sprite.size = hub->win->win_size[1] / sprite.distance;
	padding_limit = (hub->win->win_size[1] - sprite.size) / 2;
	while (++x < hub->win->win_size[1])
	{
		if ((x > padding_limit) && (x < hub->win->win_size[1] - padding_limit))
		{
			if (y == -1 || y >= texture.height)
				y = ft_y_init(texture, sprite.size, x, padding_limit);
			if ((pixel = ft_sp_color(texture, sprite, y)) != -16777216 &&
					pixel != 9961608)
				hub->win->img_data[x * hub->win->win_size[0] + i] = pixel;
			y += (float)texture.height / (float)sprite.size;
		}
	}
}

void	ft_draw_sprites(t_hub *hub, double ray, int i, t_coord check_pt)
{
	t_coord	here;
	t_coord	const_add;

	here = check_pt;
	const_add.x = cos(ray) * CHECK_STEP;
	const_add.y = sin(ray) * CHECK_STEP;
	while (same_pos(check_pt, here))
	{
		check_pt.y += const_add.y;
		check_pt.x += const_add.x;
	}
	if (is_outside_map(hub, check_pt) || map_is_what(hub, check_pt, ' '))
		return ;
	while (!is_outside_map(hub, check_pt) &&
		!map_is_what(hub, check_pt, 1) && !map_is_what(hub, check_pt, 2))
	{
		check_pt.y += const_add.y;
		check_pt.x += const_add.x;
	}
	if (is_outside_map(hub, check_pt) || !map_is_what(hub, check_pt, 2))
		return ;
	else
		ft_draw_sprites(hub, ray, i, check_pt);
	ft_draw_sp_ray(hub, i, ft_sprites(hub, check_pt, ray),
												hub->env->text.sprite);
}
