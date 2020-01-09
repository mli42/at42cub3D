/***************************************************************\
|                                              # #    ###       |
|     Author: L                                # #      #       |
|     Mail:                                    ###    ###       |
|     Creation date: 2019/12/19 16:02:00         #    #         |
|                                                #    ###       |
\***************************************************************/

#include "cub3d.h"

void	ft_remove_draw(t_win *draw)
{
	if (draw->mlx && draw->win)
		mlx_destroy_window(draw->mlx, draw->win);
	if (draw->mlx && draw->img)
		mlx_destroy_image(draw->mlx, draw->img);
	ft_free((void **)&draw);
}

void	ft_remove_parse(t_parsing *parse)
{
	int i;

	i = 0;
	while (i < parse->map_size)
		ft_free((void **)(&parse->map[i++]));
	ft_free((void **)(&parse->map));
	ft_free((void **)&parse->txt_w);
	ft_free((void **)&parse);
}

int		ft_remove_all(t_param *hub)
{
	if (hub != NULL)
	{
		if (hub->draw)
			ft_remove_draw(hub->draw);
		if (hub->parse)
			ft_remove_parse(hub->parse);
		ft_free((void **)&hub->space);
		ft_free((void **)&hub->funct);
	}
	ft_free((void **)&hub);
	write(1, "Process stoped.\n", 16);
	return (1);
}
