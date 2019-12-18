/***************************************************************\
|                                              # #    ###       |
|     Author: L                                # #      #       |
|     Mail:                                    ###    ###       |
|     Creation date: 2019/12/18 00:09:35         #    #         |
|                                                #    ###       |
\***************************************************************/

#include "cub3d.h"

void    ft_winsize(int tab[2])
{
	tab[0] = WIN_X;
	tab[1] = WIN_Y;
}

char    *ft_map(int fd)
{
	if (fd <= -1)
		return (NULL);
	return (malloc(1));
}

int square_postion_x = 0;
int square_postion_y = 0;
int square_size = 100;

void    ft_draw_square(t_win *draw)
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

int		fct(int keycode, void *param)
{
	t_win   *draw;

	draw = (t_win *)param;
	//      printf("%d\n", keycode);

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
//	ft_draw(draw);
	return (1);
}
