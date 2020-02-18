/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:30:49 by mli               #+#    #+#             */
/*   Updated: 2020/02/18 19:32:05 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef struct	s_sp
{
	char	face;
	int		size;
	double	distance;
	t_coord	pos; // ?
	double	offset; // ?
}				t_sp;

t_sp	ft_sprites(char face, double distance, t_coord pos)
{
	t_sp sprite;

	sprite.face = face;
	sprite.distance = distance;
	sprite.pos = pos;
	return (sprite);
}

double	ft_points_dist(t_coord a, t_coord b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
	return (hypot(b.x - a.x, b.y - a.y));
}

int		same_pos(t_coord a, t_coord b)
{
	if (((int)a.x) == ((int)b.x) && ((int)a.y) == (int)b.y)
		return (1);
	return (0);
}

void	ft_draw_sprites(t_hub *hub, double ray, int i, t_coord wont_check)
{
	int		h_v;
	t_sp	sprite; // ??
	t_coord	check_pt;
	t_coord	const_add;

	int **map = hub->env->map;

	check_pt.x = hub->player->entity.pos.x;
	check_pt.y = hub->player->entity.pos.y;
	const_add.x = cos(ray) * CHECK_STEP;
	const_add.y = sin(ray) * CHECK_STEP;
	while (same_pos(check_pt, wont_check))
	{
		check_pt.y += const_add.y;
		check_pt.x += const_add.x;
	}
	while ((map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 1) &&
		(map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 2))
	{
		check_pt.y += const_add.y;
		h_v = (map[(int)check_pt.y + 1][(int)check_pt.x + 1] == 2 ? 'h' : 'v');
		check_pt.x += const_add.x;
	}
	if (map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 2)
		return ;
//	else
//	{
//		ft_putchar('a');
//		ft_draw_sprites(hub, ray, i, check_pt);
//	}
	check_pt.x = floor(check_pt.x) + 0.5;
	check_pt.y = floor(check_pt.y) + 0.5;
	sprite = ft_sprites(ft_face(ray, h_v),
			ft_points_dist(hub->player->entity.pos, check_pt),
			check_pt);
	(void)ray;
	(void)i;
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
