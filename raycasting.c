/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:27:03 by mli               #+#    #+#             */
/*   Updated: 2020/02/11 19:32:17 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int color_set[5] = {0, ORANGE, YELLOW, D_RED, GREY};

float	ft_y_init(t_data texture, t_walls walls, int x, int padding_limit)
{
	float	y;

	y = (float)(x - (padding_limit > 0 ? padding_limit :
	padding_limit * walls.size)) / (float)walls.size * (float)texture.height /
	(float)walls.size - walls.distance / 10;

	return (y);
}

int		ft_color(t_data texture, t_walls walls, float y)
{
	if (walls.face == 'N')
		return (is_north(texture, walls, y));
	if (walls.face == 'E')
		return (is_east(texture, walls, y));
	if (walls.face == 'S')
		return (is_south(texture, walls, y));
	if (walls.face == 'W')
		return (is_west(texture, walls, y));
	return (0);
}

t_data	ft_which_text(t_hub *hub, t_walls walls)
{
	if (walls.face == 'N')
		return (hub->env->text.north);
	else if (walls.face == 'E')
		return (hub->env->text.east);
	else if (walls.face == 'S')
		return (hub->env->text.south);
	return (hub->env->text.west);
}

void	ft_drawing_ray(t_hub *hub, int i, t_walls walls)
{
	int		x;
	int		padding_limit;
	float	y;
	int		pixel;
	t_data	texture;

	x = -1;
	y = -1;
	walls.size = hub->win->win_size[1] / walls.distance;
	padding_limit = (hub->win->win_size[1] - walls.size) / 2;
	texture = ft_which_text(hub, walls);
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
			if (y == -1)
				y = ft_y_init(texture, walls, x, padding_limit);
			pixel = ft_color(texture, walls, y);
			y += (float)texture.height / (float)walls.size;
			hub->win->img_data[x * hub->win->win_size[0] + i] = pixel;
		}
	}
}

int		ft_face(double current_ray, int h_v)
{
	if (current_ray < 0)
		current_ray += PI2;
	if (current_ray >= 0 && current_ray <= M_PI && h_v == 'h')
		return ('S');
	if (current_ray >= M_PI && current_ray <= PI2 && h_v == 'h')
		return ('N');
	if (current_ray >= M_PI/2 && current_ray <= 3 * M_PI/2 && h_v == 'v')
		return ('W');
	return ('E');
}

void	ft_raycasting(t_hub *hub, double ray, int i)
{
	int			h_v;
	double		distance;
	t_coord		check_pt;
	t_coord		const_add;
	int			**map;

	distance = 0;
	map = hub->env->map;
	check_pt.x = hub->player->entity.pos.x;
	check_pt.y = hub->player->entity.pos.y;
	const_add.x = cos(ray) * CHECK_STEP;
	const_add.y = sin(ray) * CHECK_STEP;
	while (map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 1)
	{
		check_pt.y += const_add.y;
		h_v = (map[(int)check_pt.y + 1][(int)check_pt.x + 1] == 1 ? 'h' : 'v');
		check_pt.x += const_add.x;
		distance += CHECK_STEP;
	}
	distance *= cos(ft_abs_double(hub->player->entity.dir_rad - ray));
	ft_drawing_ray(hub, i, ft_walls(ft_face(ray, h_v), distance, check_pt));
}

void	ft_draw(t_hub *hub)
{
	int				i;
	static int		ray_max;
	double			current_ray;
	static double	ray_size;
	t_coord			check_pt;

	check_pt.x = (int)hub->player->entity.pos.x + 1;
	check_pt.y = (int)hub->player->entity.pos.y + 1;
	ft_recalculate_povs(hub->player);
	ray_size = POV_60 / hub->win->win_size[0];
	current_ray = hub->player->pov_max_rad + ray_size;
	i = -1;
	ray_max = hub->win->win_size[0];
	while (++i < ray_max)
	{
		if (check_pt.x > hub->env->map_width[(int)check_pt.y] - 1 ||
	check_pt.x < 0 || check_pt.y < 0 || check_pt.y > hub->env->map_height - 1)
			ft_drawing_ray(hub, i, ft_walls('D', CHECK_STEP, check_pt));
		else
			ft_raycasting(hub, current_ray, i);
		current_ray += ray_size;
	}
	ft_life(hub);
	mlx_put_image_to_window(hub->win->mlx, hub->win->win, hub->win->img, 0, 0);
}
