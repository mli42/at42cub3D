/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:27:03 by mli               #+#    #+#             */
/*   Updated: 2019/12/29 04:36:39 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[9][9];

int color_set[5] = {0, ORANGE, YELLOW, D_RED, GREY};

int		ft_color(t_param *hub, t_point wall)
{
	t_point position;

	// Point A
	position.x = hub->space->pos.x;
	position.y = hub->space->pos.y;
	// Zone B
	if (wall.x <= position.x && wall.y >= position.y)
		return (color_set[2]);
	// Zone C
	if (wall.x >= position.x && wall.y >= position.y)
		return (color_set[1]);
	// Zone D
	if (wall.x <= position.x && wall.y <= position.y)
		return (color_set[3]);
	// Zone E
	return (color_set[4]);
}

void	ft_drawing_ray(t_param *hub, int i, double distance, t_point point)
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
		color = ft_color(hub, point);
		if (x < padding_limit)
			hub->draw->img_data[x * hub->draw->win_size[0] + i] = SKYBLUE;
		else if (x > hub->draw->win_size[0] - padding_limit)
			hub->draw->img_data[x * hub->draw->win_size[0] + i] = GREY_FLOOR;
		else
			hub->draw->img_data[x * hub->draw->win_size[0] + i] = color;
	}
}

void	ft_raycasting(t_param *hub, double current_ray, int i)
{
	t_coord checking_point;
	t_point point;
	double distance;
	t_coord const_add;

	distance = 0;
	checking_point.x = hub->space->pos.x;
	checking_point.y = hub->space->pos.y;
	point.y = (int)checking_point.y + 1;
	point.x = (int)checking_point.x + 1;
	const_add.x = cos(current_ray) * CHECK_STEP;
	const_add.y = sin(current_ray) * CHECK_STEP;
	while (map[point.y][point.x] == 0)
	{
		checking_point.x += const_add.x;
		checking_point.y += const_add.y;
		point.y = (int)checking_point.y + 1;
		point.x = (int)checking_point.x + 1;
		distance += CHECK_STEP;
	}
	distance *= cos(ft_abs_double(hub->space->dir_rad - current_ray));
	ft_drawing_ray(hub, i, distance, point);
}

void	ft_draw(t_param *hub)
{
//	static int w = 0;
//	w++;
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
//		printf("\tCURRENT RAY : %lf\t", current_ray * (180/M_PI));
		ft_raycasting(hub, current_ray, i);
		current_ray += ray_size;
	}
	mlx_put_image_to_window(hub->draw->mlx, hub->draw->win, hub->draw->img, 0, 0);
}
