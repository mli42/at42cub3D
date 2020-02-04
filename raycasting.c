/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:27:03 by mli               #+#    #+#             */
/*   Updated: 2020/02/04 14:53:32 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int color_set[5] = {0, ORANGE, YELLOW, D_RED, GREY};

int		ft_color(t_hub *hub, t_walls walls, int size, float x)
{
	int		pixel;
	int		index;
	static float y = -1;

	if (y == -1  || y >= x * hub->env->text.south.height)
		y = x * (float)hub->env->text.south.height / (float)size;

	if (walls.face == 'N')
		return (color_set[1]);
	if (walls.face == 'E')
		return (color_set[2]);
	if (walls.face == 'S')
	{
		index = ((int)y) * hub->env->text.south.height +
			(fmod(walls.check_pt.x + 1, 1)) * hub->env->text.south.width;
		pixel = hub->env->text.south.data[index];
		y += (float)hub->env->text.south.height / (float)size;
		return (pixel);
	}
	return (color_set[4]);
}

void	ft_drawing_ray(t_hub *hub, int i, t_walls walls)
{
	int x;
	int size;
	int color[3];
	int padding_limit;

	x = -1;
	color[1] = hub->env->ceiling_color;
	color[2] = hub->env->floor_color;
	size = hub->win->win_size[1] / walls.distance;
	padding_limit = (hub->win->win_size[1] - size) / 2;
	while (++x < hub->win->win_size[1])
	{
		if (x < padding_limit)
			hub->win->img_data[x * hub->win->win_size[0] + i] = color[1];
		else if (x > hub->win->win_size[1] - padding_limit)
			hub->win->img_data[x * hub->win->win_size[0] + i] = color[2];
		else
		{
			color[0] = ft_color(hub, walls, size, (float)(x - padding_limit) / (float)size);
			hub->win->img_data[x * hub->win->win_size[0] + i] = color[0];
		}
	}
}

int		ft_face(double current_ray, int h_v)
{
	if (current_ray < 0)
		current_ray += PI2;
	if (current_ray >= 0 && current_ray <= M_PI && h_v == 'h')
		return ('N');
	if (current_ray >= M_PI && current_ray <= PI2 && h_v == 'h')
		return ('S');
	if (current_ray >= M_PI/2 && current_ray <= 3 * M_PI/2 && h_v == 'v')
		return ('E');
	return ('W');
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
		if (check_pt.x > hub->env->map_width - 1 || check_pt.x < 0 ||
			check_pt.y < 0 || check_pt.y > hub->env->map_height - 1)
			ft_drawing_ray(hub, i, ft_walls('D', CHECK_STEP, check_pt));
		else
			ft_raycasting(hub, current_ray, i);
		current_ray += ray_size;
	}
	ft_life(hub);
	mlx_put_image_to_window(hub->win->mlx, hub->win->win, hub->win->img, 0, 0);
}
