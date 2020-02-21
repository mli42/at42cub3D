/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/02/21 11:25:17 by mli              ###   ########.fr       */
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
	pos.x = (int)pos.x + 0.5;
	pos.y = (int)pos.y + 0.5;
	sprite.center = pos;
	return (sprite);
}

char	next_check_pt(t_coord *check_pt, t_coord const_add, int **map)
{
	char h_v;

	check_pt->y += const_add.y;
	h_v = (map[(int)check_pt->y + 1][(int)check_pt->x + 1] == 2 ? 'h' : 'v');
	check_pt->x += const_add.x;
	return (h_v);
}

void	ft_sprite_next(t_hub *hub, int i, t_sp sprite, double ray)
{
	t_faffine	dir;
	t_faffine	perp;
	t_faffine	cast;
	t_coord		m;

	dir = ft_dirf(hub->player->entity.pos, sprite.center);
	perp = ft_perpf(dir, sprite.center);
	cast = ft_castf(ray, hub->player->entity.pos);
	m = resolve_eq(perp, cast);

	(void)hub;
	(void)i;
	(void)sprite;

//	sprite.offset = ft_sp_offset(sprite, ray);
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
	while ((hub->env->map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 1) &&
		(hub->env->map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 2))
		h_v = next_check_pt(&check_pt, const_add, hub->env->map);
	if (hub->env->map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 2)
		return ;
	else
		ft_draw_sprites(hub, ray, i, check_pt);
	ft_sprite_next(hub, i, ft_sprites(ft_face(ray, h_v),
			ft_dist_to_sp(hub->player->entity.pos, check_pt), check_pt), ray);

}

/*
void	ft_raycasting(t_hub *hub, int **map, double ray, int i)
{
	double		distance;

	distance = 0;
	distance *= cos(ft_abs_double(hub->player->entity.dir_rad - ray));
	ft_drawing_ray(hub, i, walls, ft_which_text(hub, walls));
}


int		ft_color(t_data texture, t_walls walls, float y)
{
	if (walls.face == 'W' || walls.face == 'S')
		return (texture.data[(int)(((int)y) * texture.height + texture.width *
(1 - fmod((walls.face == 'S' ? walls.check_pt.x : walls.check_pt.y) + 1, 1)))]);
	else if (walls.face == 'N' || walls.face == 'E')
		return (texture.data[(int)(((int)y) * texture.height + texture.width *
	(fmod((walls.face == 'N' ? walls.check_pt.x : walls.check_pt.y) + 1, 1)))]);
	else
		return (0);
}

float	ft_y_init(t_data texture, t_walls walls, int x, int padding_limit)
{
	return ((float)(x - (padding_limit > 0 ? padding_limit :
	padding_limit * walls.size)) / (float)walls.size * (float)texture.height /
	(float)walls.size);
}

#########################################

if (!(x < padding_limit) && !(x > hub->win->win_size[1] - padding_limit))

if (ft_color(texture, walls, y) == -16777216)
{
    y += (float)texture.height / (float)walls.size;
    continue ;
}
hub->win->img_data[x * hub->win->win_size[0] + i] = ft_color(texture, walls, y);
y += (float)texture.height / (float)walls.size;

#########################################

void	ft_drawing_ray(t_hub *hub, int i, t_walls walls, t_data texture)
{
	int		x;
	int		padding_limit;
	float	y;

	x = -1;
	y = -1;
	walls.size = hub->win->win_size[1] / walls.distance;
	padding_limit = (hub->win->win_size[1] - walls.size) / 2;
	while (++x < hub->win->win_size[1])
	{
		if (x < padding_limit)
			hub->win->img_data[x * hub->win->win_size[0] + i] =
				hub->env->ceiling_color;
		else if (x > hub->win->win_size[1] - padding_limit)
			hub->win->img_data[x * hub->win->win_size[0] + i] =
				hub->env->floor_color;
		else
		{
			if (y == -1 || y >= texture.height)
				y = ft_y_init(texture, walls, x, padding_limit);
			hub->win->img_data[x * hub->win->win_size[0] + i] =
				ft_darker(ft_color(texture, walls, y), walls.distance);
			y += (float)texture.height / (float)walls.size;
		}
	}
}
*/
