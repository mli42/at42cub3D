/***************************************************************\
|                                              # #    ###       |
|     Author: L                                # #      #       |
|     Mail:                                    ###    ###       |
|     Creation date: 2019/12/19 16:02:00         #    #         |
|                                                #    ###       |
\***************************************************************/

#include "cub3d.h"

int		ft_remove_all(t_param *hub)
{
	if (hub != NULL)
	{
		if (hub->draw)
			; // Destroy the MLX
		free(hub->draw);
		hub->draw = NULL;

		free(hub->space);
		hub->space = NULL;

		free(hub->funct);
		hub->funct = NULL;
	}
	free(hub);
	write(1, "Process stoped.\n", 16);
	return (1);
}
