/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:35:51 by mli               #+#    #+#             */
/*   Updated: 2019/12/07 11:18:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		*ft_winsize(int tab[2])
{
	tab[0] = 1000;
	tab[1] = 1000;
	return (tab);
}

char	*ft_map(int fd)
{
	if (fd <= -1)
		return (NULL);
	return (malloc(1));
}


enum varName
{
	bit_per_pixel,
	sizeLine,
	endian,
	end
};

int square_postion_x = 0;
int square_postion_y = 0;
int square_size = 100;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void 	*img;
	int 	*img_data;
	int		win_size[2];
}				t_win;

int		ft_cub3d(t_win *draw, char *map)
{
	int 	var[3];

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

void ft_draw(t_win *draw)
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
				x < square_size && y < square_size)
				draw->img_data[y * draw->win_size[0] + x] = 0x7fffff;
			else
				draw->img_data[y * draw->win_size[0] + x] = 0;
		}
	}
	mlx_put_image_to_window(draw->mlx, draw->win, draw->img, 0, 0);
}

int 	fct(int keycode, void *param)
{
	t_win	*draw;

	draw = (t_win *)param;
//	printf("%d\n", keycode);

	if (keycode == 53)
		exit (1);
	if (keycode == RIGHT)
		square_postion_x += 10;
	if (keycode == LEFT)
		square_postion_x -= 10;
	if (keycode == UP)
		square_postion_y += 10;
	if (keycode == DOWN)
		square_postion_x -= 10;
	ft_draw(draw);
	return (1);
}

int		main(int argc, char **argv)
{
	t_win 	*draw;
	char	*map;

	if (argc == 2)
	{
		if (!(draw = (t_win *)ft_memalloc(sizeof(t_win *))))
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
		mlx_key_hook(draw->win, fct, draw);
		mlx_loop(draw->mlx);
	}
	else
		return (ft_error("Just give me ONE map"));
	return (0);
}
