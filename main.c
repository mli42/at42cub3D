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

void	ft_winsize(int tab[2])
{
	tab[0] = WIN_X;
	tab[1] = WIN_Y;
}

char	*ft_map(int fd)
{
	if (fd <= -1)
		return (NULL);
	return (malloc(1));
}

int square_postion_x = 0;
int square_postion_y = 0;
int square_size = 100;

int		ft_cub3d(t_win *draw, char *map)
{
	int		var[3];

	if (!(draw->img = mlx_new_image(draw->mlx, draw->win_size[0],
			draw->win_size[1])))
		return (-1);
	if (!(draw->img_data = (int *)mlx_get_data_addr(draw->img,
			&var[0], &var[1], &var[2])))
		return (-1);
	(void)map;

//	if (var[sizeLine] > 10)
//		exit(0);

	return (1);
}

void	ft_draw_square(t_win *draw)
{
	int x;
	int y;

	y = -1;
	while (++y < draw->win_size[0])
	{
		x = -1;
		while (++x < draw->win_size[1])
		{
			if (x > square_postion_x && y > square_postion_y &&
				x < square_size + square_postion_x &&
				y < square_size + square_postion_y)
				draw->img_data[y * draw->win_size[0] + x] = 0x7fffff;
			else
				draw->img_data[y * draw->win_size[0] + x] = 0;
		}
	}
	mlx_put_image_to_window(draw->mlx, draw->win, draw->img, 0, 0);
}

		//			FLOATS
	float pos[2] = {3, 3}; // Being at the center;
	float v_dir[2] = {0, 1}; // Watching North;
	float pov = 1/3; // Champ de vision de 30 degres de chaque côté;
//	float v_pov_min[2] = {v_dir[x] - pov, v_dir[y]}; // POV MIN;
//	float v_pov_max[2] = {v_dir[x] + pov, v_dir[y]}; // POV MAX;

void	ft_draw(t_win *draw)
{
	(void)draw;
	v_pov_min[x] = v_dir[x] - pov;
	v_pov_min[y] = v_dir[y];
	v_pov_max[x] = v_dir[x] + pov;
	v_pov_max[y] = v_dir[y];

	printf("v_dir == x: %.1f || y: %.1f\n", v_dir[x], v_dir[y]);
}

int		fct(int keycode, void *param)
{
	t_win	*draw;

	draw = (t_win *)param;
//	printf("%d\n", keycode);

	if (keycode == 53)
		exit(1);
	else if (keycode == RIGHT)
		square_postion_x += 10;
	else if (keycode == LEFT)
		square_postion_x -= 10;
	else if (keycode == UP)
		square_postion_y -= 10;
	else if (keycode == DOWN)
		square_postion_y += 10;
	ft_draw(draw);
	return (1);
}

int		main(int argc, char **argv)
{
	t_win	*draw;
	char	*map;

	// INIT
	v_pov_min[x] = v_dir[x] - pov;
	v_pov_min[y] = v_dir[y];
	v_pov_max[x] = v_dir[x] + pov;
	v_pov_max[y] = v_dir[y];
	// INIT
	if (argc != 2)
		return (ft_error("Just give me ONE map"));
	if (!(draw = (t_win *)ft_memalloc((int)sizeof(t_win))))
		return (ft_error("Can't do any allocation"));
	if (!(map = ft_map(open(argv[1], O_RDONLY))))
		return (ft_error("Map error"));
	ft_winsize(draw->win_size);
	if (!(draw->mlx = mlx_init()))
		return (ft_error("MLX does not initialize"));
	if (!(draw->win = mlx_new_window(draw->mlx, draw->win_size[0],
					draw->win_size[1], "cub3D")))
		return (ft_error("MLX does not open a window"));
	if ((ft_cub3d(draw, map)) == -1)
		return (-1);
	ft_draw(draw);
	mlx_hook(draw->win, KeyPress, KeyPressMask, fct, draw);
	mlx_loop(draw->mlx);
	return (0);
}
