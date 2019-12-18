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
	t_param		*params;

	//      printf("%d\n", keycode);
	params = (t_param *)param;
	draw = params->draw;
	space = params->space;

	if (keycode == 53)
		exit(1);
	else if (keycode == RIGHT)
		printf("R\n");
	else if (keycode == LEFT)
		printf("L\n");
	else if (keycode == UP)
		printf("T\n");
	else if (keycode == DOWN)
		printf("B\n");
	ft_draw(*params);
	return (1);
}

int		ft_cub3d(t_win *draw, char *map)
{
	int			var[3];
	t_vectors	*space;
	t_param		param;

	if (!(space = ft_init_space()))
		return (ft_error("Malloc problem", draw));
	if (!(draw->img = mlx_new_image(draw->mlx, draw->win_size[0],
			draw->win_size[1])))
		return (ft_error("MLX can't create an image", draw));
	if (!(draw->img_data = (int *)mlx_get_data_addr(draw->img,
			&var[0], &var[1], &var[2])))
		return (ft_error("MLX can't create an image", draw));
	(void)map;

	param.draw = draw;
	param.space = space;

	ft_draw(param);
	mlx_hook(draw->win, KeyPress, KeyPressMask, ft_press_key, &param);
//	if (var[sizeLine] > 10)
//		exit(0);

	return (1);
}

void	ft_draw(t_param param)
{
	t_win		*draw;
	t_vectors	*space;
	static int i = 0;

	draw = param.draw;
	space = param.space;

	// Calculer les murs et les dessiner
	if (i == 0 || i == 1)
		ft_recalculate_povs(space);

	// ft_draw_map();
	// ft_draw_minimap();
	
	i++;
}

int		main(int argc, char **argv)
{
	t_win	*draw;
	char	*map;

	if (argc != 2)
		return (ft_error("Just give me ONE map", NULL));
	if (!(draw = (t_win *)ft_memalloc((int)sizeof(t_win))))
		return (ft_error("Can't do any allocation", NULL));
	if (!(map = ft_map(open(argv[1], O_RDONLY))))
		return (ft_error("Map error", draw));
	ft_winsize(draw->win_size);
	if (!(draw->mlx = mlx_init()))
		return (ft_error("MLX does not initialize", draw));
	if (!(draw->win = mlx_new_window(draw->mlx, draw->win_size[0],
					draw->win_size[1], "cub3D")))
		return (ft_error("MLX does not open a window", draw));
	if ((ft_cub3d(draw, map)) == -1)
		return (-1);
	mlx_loop(draw->mlx);
	return (0);
}
