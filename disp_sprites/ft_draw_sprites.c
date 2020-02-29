/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/02/29 15:11:09 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

t_sp	ft_sprites(char face, double distance, t_coord pos)
{
	t_sp sprite;

	sprite.face = face;
	sprite.distance = distance;
	sprite.hit = pos;
	pos.x = (int)pos.x + 0.500001;
	pos.y = (int)pos.y + 0.500001;
	sprite.center = pos;
	return (sprite);
}

char	next_check_pt(t_coord *check_pt, t_coord const_add, int **map)
{
	char h_v;

	check_pt->y += const_add.y;
	h_v = (map[(int)check_pt->y][(int)check_pt->x] == 2 ? 'h' : 'v');
	check_pt->x += const_add.x;
	return (h_v);
}

int		ft_sp_color(t_data texture, t_sp sprite, float y)
{
	if (sprite.face == 'S' || sprite.face == 'W')
		return (texture.data[(int)(((int)y) * texture.height +
					(1 - sprite.offset) * texture.width)]);
	else if (sprite.face == 'N' || sprite.face == 'E')
		return (texture.data[(int)(((int)y) * texture.height +
					sprite.offset * texture.width)]);
	else
		return (0);
}

void	ft_draw_sp_ray(t_hub *hub, int i, t_sp sprite, t_data texture)
{
	int		x;
	float	y;
	int		pixel;
	int		padding_limit;

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
	int		h_v;
	t_coord	here;
	t_coord	const_add;

	here = check_pt;
	const_add.x = cos(ray) * CHECK_STEP;
	const_add.y = sin(ray) * CHECK_STEP;
	while (same_pos(check_pt, here))
		next_check_pt(&check_pt, const_add, hub->env->map);
	if (is_outside_map(hub, check_pt))
		return ;
	while (!map_is_what(hub, check_pt, 1) && !map_is_what(hub, check_pt, 2))
		h_v = next_check_pt(&check_pt, const_add, hub->env->map);
	if (!map_is_what(hub, check_pt, 2))
		return ;
	else
		ft_draw_sprites(hub, ray, i, check_pt);
	ft_sprite_next(hub, i, ft_sprites(ft_face(ray, h_v),
			ft_dist_to_sp(hub->player->entity.pos, check_pt), check_pt), ray);
}
