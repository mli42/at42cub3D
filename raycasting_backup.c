/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:27:03 by mli               #+#    #+#             */
/*   Updated: 2019/12/21 19:56:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[7][7];

/*				{{1, 1, 1, 1, 1, 1, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 1, 1, 1, 1, 1, 1}};			*/

int color_set[5] = {0, ORANGE, BLUE, D_RED, GREY};

void	ft_drawing_ray(t_win *draw, int i, double distance, int touched)
{
	int x;
	int size;
	int padding_limit;

	int color;
	x = -1;
	size = draw->win_size[0]/distance;
	padding_limit = draw->win_size[0] - size;
	padding_limit /= 5;
//	printf("Size and distance: %d, %lf\n", size, distance);
	while (++x < draw->win_size[0])
	{
		color = color_set[touched];
		if (x >= padding_limit && x <= draw->win_size[0] - padding_limit)
			draw->img_data[x * draw->win_size[0] + i] = color;
		else
			draw->img_data[x * draw->win_size[0] + i] = 0;
	}
	mlx_put_image_to_window(draw->mlx, draw->win, draw->img, 0, 0);
}

void	ft_raycasting(t_win *draw, t_vectors *space, int i)
{
	double current_ray;
	t_coord checking_point;
	double distance;
	static const double step = (1.0/10.0);
	t_coord const_add;

	current_ray = (ft_abs_double(space->pov_max_rad - space->pov_min_rad)
		/ draw->win_size[1] * i) + space->pov_max_rad;
// Current ray
	printf("\t\tCURRENT RAY : %lf\n", current_ray * (180/M_PI));

	distance = 0;
	checking_point.x = space->pos.x;
	checking_point.y = space->pos.y;
	const_add.x = cos(current_ray) * step;
	const_add.y = sin(current_ray) * step;
	while (map[(int)checking_point.y + 1][(int)checking_point.x + 1] == 0)
	{
		checking_point.x += const_add.x;
		checking_point.y += const_add.y;
		distance += step;

	//	printf("Checkpoint : X=%lf\tY=%lf\n", checking_point.x, checking_point.y);
//		printf("Watching (degrees) %lf\n", atan2(checking_point.y, checking_point.x) * (180/M_PI));
	}
//	printf("Case final: X=%d\tY=%d\n", (int)checking_point.x + 1, (int)checking_point.y + 1);
//	printf("Distance found : %lf\n", distance);
	ft_drawing_ray(draw, i, distance, map[(int)checking_point.y + 1][(int)checking_point.x + 1]);
}

void	ft_draw(t_param *hub)
{
//	static int w = 0;
//	w++;
	int				i;
	static int		ray_max;

	i = -1;
	ft_recalculate_povs(hub->space);
	ray_max = hub->draw->win_size[1];
	while (++i < ray_max)
		ft_raycasting(hub->draw, hub->space, i);

	// ft_draw_map();
	// ft_draw_minimap();
}
