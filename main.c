/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:35:51 by mli               #+#    #+#             */
/*   Updated: 2019/12/13 17:22:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[7][7] = {{1, 1, 1, 1, 1, 1, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 1, 1, 1, 1, 1, 1}};

int		ft_press_key(int keycode, void *param)
{
	t_win		*draw;
	t_vectors	*space;
	t_param		*hub;

//	printf("Key: %d\n", keycode);
	hub = (t_param *)param;
	draw = hub->draw;
	space = hub->space;

	if (keycode == EXIT_CODE)
		exit(ft_remove_all(hub));
	else if (keycode == ARROW_RIGHT)
	{
		space->dir.x = cos(space->dir_rad - RAD_10);
		space->dir.y = sin(space->dir_rad - RAD_10);
		printf("Pressed ARROW_RIGHT\n");
	}
	else if (keycode == ARROW_LEFT)
	{
		space->dir.x = cos(space->dir_rad + RAD_10);
		space->dir.y = sin(space->dir_rad + RAD_10);
		printf("Pressed ARROW_LEFT\n");
	}
	else if (keycode == ARROW_UP)
		printf("Pressed ARROW_UP\n");
	else if (keycode == ARROW_DOWN)
		printf("Pressed ARROW_DOWN\n");
	else if (keycode == A_KEY)
		printf("Pressed A-key\n");
	else if (keycode == S_KEY)
		printf("Pressed S-key\n");
	else if (keycode == D_KEY)
		printf("Pressed D-key\n");
	else if (keycode == W_KEY)
		printf("Pressed W-key\n");
	ft_draw(hub);
	return (1);
}

int		ft_cub3d(t_param *hub, char *map)
{
	int			var[3];
	t_win		*draw;
	t_vectors	*space;

	if (!(hub->space = ft_init_space()))
		return (ft_error("Malloc problem", hub));
	draw = hub->draw;
	space = hub->space;
	if (!(draw->img = mlx_new_image(draw->mlx, draw->win_size[0],
			draw->win_size[1])))
		return (ft_error("MLX can't create an image", hub));
	if (!(draw->img_data = (int *)mlx_get_data_addr(draw->img,
			&var[0], &var[1], &var[2])))
		return (ft_error("MLX can't create an image", hub));
	(void)map;

	ft_draw(hub);
	mlx_hook(draw->win, KeyPress, KeyPressMask, ft_press_key, hub);
//	if (var[sizeLine] > 10)
//		exit(0);

	return (1);
}

double	ft_raycasting(t_win *draw, t_vectors *space, int i)
{
	double current_ray;
	t_coord checking_point;
	double distance;
	const double step = (1.0/10.0);

	current_ray = ft_abs_double(space->pov_max_rad - space->pov_min_rad)
		/ draw->win_size[1] * i + space->pov_min_rad;
// Current ray
	printf("\t\tCURRENT RAY : %lf\n", current_ray * (180/M_PI));

	distance = 0;
//	checking_point.x = space->pos.x + cos(current_ray)/100;
//	checking_point.y = space->pos.y + sin(current_ray)/100;
	checking_point.x = 0;
	checking_point.y = 0;
	while (map[(int)checking_point.y + 1][(int)checking_point.x + 1] == 0)
	{
		checking_point.x = cos(current_ray) * distance;
		checking_point.y = sin(current_ray) * distance;
	
//		checking_point.x += step;
//		checking_point.y += step;

		distance += step;

	//	printf("Checkpoint : X=%lf\tY=%lf\n", checking_point.x, checking_point.y);
//		printf("Watching (degrees) %lf\n", atan2(checking_point.y, checking_point.x) * (180/M_PI));
	}
	printf("Case final: X=%d\tY=%d\n", (int)checking_point.x + 1, (int)checking_point.y + 1);
	printf("Distance found : %lf\n", distance);
	return (distance);
}

void	ft_draw(t_param *hub)
{
//	static int w = 0;
//	w++;
	t_win		*draw;
	t_vectors	*space;
	int			ray_max;
	int			i;
	double distance;

	draw = hub->draw;
	space = hub->space;
	ft_recalculate_povs(space);

	i = -1;
	ray_max = hub->draw->win_size[1];
	while (++i < ray_max)
	{
		distance = ft_raycasting(hub->draw, hub->space, i);
		ft_drawing_map(hub->draw, hub->space);
	}

	// ft_draw_map();
	// ft_draw_minimap();
	
	mlx_put_image_to_window(draw->mlx, draw->win, draw->img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_param	*hub;
	t_win	*draw;
	char	*map;

	if (argc != 2)
		return (ft_error("Just give me ONE map", NULL));
	if (!(hub = (t_param *)ft_memalloc((int)sizeof(t_param))))
		return (ft_error("Can't do any allocation", NULL));
	if (!(hub->draw = (t_win *)ft_memalloc((int)sizeof(t_win))))
		return (ft_error("Can't do any allocation", hub));
	draw = hub->draw;
	if (!(map = ft_map(open(argv[1], O_RDONLY))))
		return (ft_error("Map error", hub));
	ft_winsize(draw->win_size);
	if (!(draw->mlx = mlx_init()))
		return (ft_error("MLX does not initialize", hub));
	if (!(draw->win = mlx_new_window(draw->mlx, draw->win_size[0],
					draw->win_size[1], "cub3D")))
		return (ft_error("MLX does not open a window", hub));
	if ((ft_cub3d(hub, map)) == -1)
		return (-1);
	mlx_loop(draw->mlx);
	return (0);
}
