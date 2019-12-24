/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:35:51 by mli               #+#    #+#             */
/*   Updated: 2019/12/24 03:58:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[7][7] = {{1, 2, 3, 4, 3, 2, 1},
				{1, 0, 0, 0, 1, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 0, 1},
				{3, 3, 3, 3, 3, 3, 3}};

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

int		main(int argc, char **argv)
{
	t_param	*hub;
	char	*map;

	if (argc != 2)
		return (ft_error("Just give me ONE map", NULL));
	if (!(hub = (t_param *)ft_memalloc((int)sizeof(t_param))))
		return (ft_error("Can't allocate", hub));
	if (!(hub->draw = (t_win *)ft_memalloc((int)sizeof(t_win))))
		return (ft_error("Can't allocate", hub));
	if (!(hub->funct = funct_ptr_init()))
		return (ft_error("Can't allocate", hub));
	if (!(map = ft_map(open(argv[1], O_RDONLY))))
		return (ft_error("Map error", hub));
	ft_winsize(hub->draw->win_size);
	if (!(hub->draw->mlx = mlx_init()))
		return (ft_error("MLX does not initialize", hub));
	if (!(hub->draw->win = mlx_new_window(hub->draw->mlx,
			hub->draw->win_size[0], hub->draw->win_size[1], "cub3D")))
		return (ft_error("MLX does not open a window", hub));
	if ((ft_cub3d(hub, map)) == -1)
		return (-1);
	mlx_loop(hub->draw->mlx);
	return (0);
}
