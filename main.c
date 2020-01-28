/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:35:51 by mli               #+#    #+#             */
/*   Updated: 2020/01/28 16:36:43 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mouse_quit(void *param)
{
	exit(ft_remove_all((t_hub *)param));
}

int		ft_press_key(int keycode, void *param)
{
	int		i;
	int		*keymap;
	t_hub	*hub;

//	printf("Key: %d\n", keycode);
	hub = (t_hub *)param;
	keymap = (int *)hub->fct_moves->ref;
	if (keycode == EXIT_CODE)
		exit(ft_remove_all(hub));
	else
	{
		i = -1;
		// while (kmap != -1)
		while (++i < 8)
			if (keycode == keymap[i])
			{
				hub->fct_moves->fct[i](hub);
				ft_draw(hub);
				break ;
			}
	}
	return (1);
}

int		ft_init_mlx(t_hub *hub)
{
	int	var[3];

	if (!(hub->win->win = mlx_new_window(hub->win->mlx,
			hub->win->win_size[0], hub->win->win_size[1], "cub3D")))
		return (ft_error("MLX does not open a window", hub));
	if (!(hub->win->img = mlx_new_image(hub->win->mlx,
					hub->win->win_size[0], hub->win->win_size[1])))
		return (ft_error("MLX can't create an image", hub));
	if (!(hub->win->img_data = (int *)mlx_get_data_addr(hub->win->img,
			&var[bit_per_pixel], &var[sizeLine], &var[endian])))
		return (ft_error("MLX can't create an image", hub));
	ft_draw(hub);
	mlx_hook(hub->win->win, KeyPress, KeyPressMask, ft_press_key, hub);
	mlx_hook(hub->win->win, DestroyNotify, 0, ft_mouse_quit, hub);
	return (1);
}

t_hub	*ft_hub_alloc(void)
{
	t_hub *hub;

	if (!(hub = (t_hub *)ft_memalloc(sizeof(t_hub))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->win = (t_win *)ft_memalloc(sizeof(t_win))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->player = (t_player *)ft_memalloc(sizeof(t_player))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->fct_moves = fct_moves_ptr_init()))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->env = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(ft_error("Can't allocate", hub));
	return (hub);
}

int		main(int argc, char **argv)
{
	t_hub *hub;

	if (argc != 2 && !(argc == 3 &&
		(!ft_strcmp(argv[2], "-save") || !ft_strcmp(argv[2], "--save"))))
		return (ft_error("Wrong Arguments", NULL));
	if (!(hub = ft_hub_alloc()))
		return (-1);
	if (!(hub->win->mlx = mlx_init()))
		return (ft_error("MLX does not initialize", hub));
	if ((ft_parse(hub, argv[1])) == -1)
		return (-1);
	if ((ft_init_mlx(hub) == -1))
		return (-1);
	// Funct to write
	hub->player->entity.speed = FOOT_STEP;
	mlx_loop(hub->win->mlx);
	return (0);
}
