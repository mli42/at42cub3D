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

int map[5][5] = {{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1}};

int		ft_press_key(int keycode, void *param)
{
	t_win		*draw;
	t_vectors	*space;
	t_param		*hub;
	double		dir_rad;

//	printf("Key: %d\n", keycode);
	hub = (t_param *)param;
	draw = hub->draw;
	space = hub->space;

	dir_rad = atan2(space->dir.y, space->dir.x);
	if (keycode == 53)
		exit(1);
	else if (keycode == ARROW_RIGHT)
	{
		space->dir.x = cos(dir_rad - RAD_10);
		space->dir.y = sin(dir_rad - RAD_10);
		printf("Pressed ARROW_RIGHT\n");
	}
	else if (keycode == ARROW_LEFT)
	{
		space->dir.x = cos(dir_rad + RAD_10);
		space->dir.y = sin(dir_rad + RAD_10);
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
	t_vectors	*space;
	t_win		*draw;

	draw = hub->draw;
	if (!(space = ft_init_space()))
		return (ft_error("Malloc problem", draw));
	if (!(draw->img = mlx_new_image(draw->mlx, draw->win_size[0],
			draw->win_size[1])))
		return (ft_error("MLX can't create an image", draw));
	if (!(draw->img_data = (int *)mlx_get_data_addr(draw->img,
			&var[0], &var[1], &var[2])))
		return (ft_error("MLX can't create an image", draw));
	(void)map;

	hub->draw = draw;
	hub->space = space;

	ft_draw(hub);
	mlx_hook(draw->win, KeyPress, KeyPressMask, ft_press_key, hub);
//	if (var[sizeLine] > 10)
//		exit(0);

	return (1);
}

double	ft_v_check(t_win *draw, t_vectors *space, double current_ray)
{
	double distance;
	t_coord to_check;

	// premier point -> x;y
	
	// Attetion si facing down
	to_check.y = (int)space->pos.y + (current_ray < 0 ? 1 : 0);
	to_check.x = ft_abs_double(to_check.y - space->pos.y) / tan(current_ray);
	printf("X: %lf\tY:%lf\n", to_check.x, to_check.y);
	if (map[(int)to_check.y][(int)to_check.x])
		return (1);

	distance = 0;
	(void)draw;
	(void)space;
	(void)current_ray;
	return (distance);
}

void	ft_raycasting(t_win *draw, t_vectors *space, int i)
{
	double current_ray;
//	double h_dist;
	double v_dist;

	current_ray = ft_abs_double(space->pov_max_rad - space->pov_min_rad)
		/ draw->win_size[1] * i + space->pov_min_rad;
//	h_dist = ft_h_check(draw, space, current_ray);
	v_dist = ft_v_check(draw, space, current_ray);

	printf("v dist : %lf\n", v_dist);
}

void	ft_draw(t_param *hub)
{
//	static int w = 0;
//	w++;
	t_win		*draw;
	t_vectors	*space;
	int			ray_max;
	int			i;

	draw = hub->draw;
	space = hub->space;
	ft_recalculate_povs(space);

	i = -1;
	ray_max = hub->draw->win_size[1];
//	while (++i < ray_max)
	while (++i < 5)
		ft_raycasting(hub->draw, hub->space, i);

	// ft_draw_map();
	// ft_draw_minimap();
	
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
		return (ft_error("Can't do any allocation", NULL));
	draw = hub->draw;
	if (!(map = ft_map(open(argv[1], O_RDONLY))))
		return (ft_error("Map error", draw));
	ft_winsize(draw->win_size);
	if (!(draw->mlx = mlx_init()))
		return (ft_error("MLX does not initialize", draw));
	if (!(draw->win = mlx_new_window(draw->mlx, draw->win_size[0],
					draw->win_size[1], "cub3D")))
		return (ft_error("MLX does not open a window", draw));
	if ((ft_cub3d(hub, map)) == -1)
		return (-1);
	mlx_loop(draw->mlx);
	return (0);
}
