/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:27:03 by mli               #+#    #+#             */
/*   Updated: 2020/02/27 17:57:05 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

float	ft_y_init(t_data texture, int size, int x, int padding_limit)
{
	return ((float)(x - (padding_limit > 0 ? padding_limit :
	padding_limit * size)) / (float)size * (float)texture.height /
	(float)size);
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
				y = ft_y_init(texture, walls.size, x, padding_limit);
			hub->win->img_data[x * hub->win->win_size[0] + i] =
				ft_darker(ft_color(texture, walls, y), walls.distance);
			y += (float)texture.height / (float)walls.size;
		}
	}
}

void	ft_raycasting(t_hub *hub, int **map, double ray, int i)
{
	int			h_v;
	double		distance;
	t_coord		check_pt;
	t_coord		const_add;
	t_walls		walls;

	distance = 0;
	check_pt.x = hub->player->entity.pos.x;
	check_pt.y = hub->player->entity.pos.y;
	const_add.x = cos(ray) * CHECK_STEP;
	const_add.y = sin(ray) * CHECK_STEP;
	while (map[(int)check_pt.y][(int)check_pt.x] != 1)
	{
		check_pt.y += const_add.y;
		h_v = (map[(int)check_pt.y][(int)check_pt.x] == 1 ? 'h' : 'v');
		check_pt.x += const_add.x;
		distance += CHECK_STEP;
	}
	distance *= cos(ft_abs_double(hub->player->entity.dir_rad - ray));
	walls = ft_walls(ft_face(ray, h_v), distance, check_pt);
	ft_drawing_ray(hub, i, walls, ft_which_text(hub, walls));
	ft_draw_sprites(hub, ray, i, hub->player->entity.pos);
}

void	ft_draw(t_hub *hub)
{
	int				i;
	static int		ray_max;
	double			current_ray;
	static double	ray_size;
	t_coord			check_pt;

	check_pt.x = (int)hub->player->entity.pos.x;
	check_pt.y = (int)hub->player->entity.pos.y;
	ft_recalculate_povs(hub->player);
	ray_size = POV_60 / hub->win->win_size[0];
	current_ray = hub->player->pov_max_rad + ray_size;
	i = -1;
	ray_max = hub->win->win_size[0];
	while (++i < ray_max)
	{
		if (is_outside_map(hub, check_pt))
			ft_black_ray(hub, i);
		else
			ft_raycasting(hub, hub->env->map, current_ray, i);
		current_ray += ray_size;
	}
	ft_life(hub);
	mlx_put_image_to_window(hub->win->mlx, hub->win->win, hub->win->img, 0, 0);
}
