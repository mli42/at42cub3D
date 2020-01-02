/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:35:51 by mli               #+#    #+#             */
/*   Updated: 2020/01/02 01:24:58 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[9][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 1},
				{2, 0, 0, 0, 0, 0, 0, 0, 4},
				{2, 0, 0, 0, 0, 0, 0, 0, 4},
				{2, 0, 2, 0, 0, 0, 0, 0, 4},
				{2, 0, 0, 0, 0, 0, 2, 0, 4},
				{2, 0, 0, 2, 0, 0, 0, 0, 4},
				{2, 0, 0, 0, 0, 0, 2, 0, 4},
				{2, 0, 0, 0, 0, 0, 0, 0, 4},
				{3, 3, 3, 3, 3, 3, 3, 3, 3}};

int		ft_press_key(int keycode, void *param)
{
	int			i;
	t_param		*hub;
	int			*keymap;

//	printf("Key: %d\n", keycode);
	hub = (t_param *)param;
	keymap = hub->funct->key_map;

	if (keycode == EXIT_CODE)
		exit(ft_remove_all(hub));
	else
	{
		i = -1;
		// while (kmap != -1)
		while (++i < 8)
			if (keycode == keymap[i])
			{
				hub->funct->fct[i](hub);
				ft_draw(hub);
				break ;
			}
	}
	return (1);
}

int		ft_cub3d(t_param *hub)
{
	int			var[3];
	t_win		*draw;
	t_vectors	*space;

	draw = hub->draw;
	space = hub->space;
	if (!(draw->img = mlx_new_image(draw->mlx, draw->win_size[0],
			draw->win_size[1])))
		return (ft_error("MLX can't create an image", hub));
	if (!(draw->img_data = (int *)mlx_get_data_addr(draw->img,
			&var[0], &var[1], &var[2])))
		return (ft_error("MLX can't create an image", hub));

	ft_draw(hub);
	mlx_hook(draw->win, KeyPress, KeyPressMask, ft_press_key, hub);
//	if (var[sizeLine] > 10)
//		exit(0);

	return (1);
}

int		main(int argc, char **argv)
{
	t_param	*hub;

	if (argc != 2)
		return (ft_error("Just give me ONE map", NULL));
	if (!(hub = ft_hub_alloc()))
		return (-1);
	if ((ft_parse(hub, argv[1])) == -1)
		return (-1);
	if (!(hub->draw->mlx = mlx_init()))
		return (ft_error("MLX does not initialize", hub));
	if (!(hub->draw->win = mlx_new_window(hub->draw->mlx,
			hub->draw->win_size[0], hub->draw->win_size[1], "cub3D")))
		return (ft_error("MLX does not open a window", hub));
	if ((ft_cub3d(hub)) == -1)
		return (-1);
	mlx_loop(hub->draw->mlx);
	return (0);
}
