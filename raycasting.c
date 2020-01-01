/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:27:03 by mli               #+#    #+#             */
/*   Updated: 2020/01/01 21:55:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[9][9];

int color_set[5] = {0, ORANGE, YELLOW, D_RED, GREY};

int		ft_color(t_param *hub, int face)
{
	(void)hub; // Hub for textures

	if (face == 'N')
		return (color_set[1]);
	if (face == 'E')
		return (color_set[2]);
	if (face == 'S')
		return (color_set[3]);
	return (color_set[4]);
}

void	ft_drawing_ray(t_param *hub, int i, double distance, int face)
{
	int x;
	int size;
	int color;
	int padding_limit;

	x = -1;
	size = hub->draw->win_size[0] / distance;
	padding_limit = (hub->draw->win_size[0] - size) / 5;
	while (++x < hub->draw->win_size[0])
	{
		color = ft_color(hub, face);
		if (x < padding_limit)
			hub->draw->img_data[x * hub->draw->win_size[0] + i] = SKYBLUE;
		else if (x > hub->draw->win_size[0] - padding_limit)
			hub->draw->img_data[x * hub->draw->win_size[0] + i] = GREY_FLOOR;
		else
			hub->draw->img_data[x * hub->draw->win_size[0] + i] = color;
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

void	ft_raycasting(t_param *hub, double current_ray, int i)
{
	int			h_v;
	double		distance;
	t_coord		check_pt;
	t_coord		const_add;

	distance = 0;
	check_pt.x = hub->space->pos.x;
	check_pt.y = hub->space->pos.y;
	const_add.x = cos(current_ray) * CHECK_STEP;
	const_add.y = sin(current_ray) * CHECK_STEP;
	while (map[(int)check_pt.y + 1][(int)check_pt.x + 1] == 0)
	{
		check_pt.y += const_add.y;
		h_v = (map[(int)check_pt.y + 1][(int)check_pt.x + 1] != 0 ? 'h' : 'v');
		check_pt.x += const_add.x;
		distance += CHECK_STEP;
	}
	distance *= cos(ft_abs_double(hub->space->dir_rad - current_ray));
	ft_drawing_ray(hub, i, distance, ft_face(current_ray, h_v));
}

void	ft_draw(t_param *hub)
{
	int				i;
	static int		ray_max;
	double			current_ray;
	static double	ray_size;

	ft_recalculate_povs(hub->space);
	ray_size = POV_60 / hub->draw->win_size[1];
	current_ray = hub->space->pov_max_rad + ray_size;
	i = -1;
	ray_max = hub->draw->win_size[1];
	while (++i < ray_max)
	{
		ft_raycasting(hub, current_ray, i);
		current_ray += ray_size;
	}
	mlx_put_image_to_window(hub->draw->mlx, hub->draw->win, hub->draw->img, 0, 0);
}
