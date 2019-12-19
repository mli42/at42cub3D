/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:00:25 by mli               #+#    #+#             */
/*   Updated: 2019/12/10 12:06:28 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_windraw(t_win *draw)
{
	free(draw);
	draw = NULL;
}

int		ft_error(char *str, t_win *draw)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	ft_free_windraw(draw);
	return (-1);
}

t_vectors	*ft_init_space(void)
{
	t_vectors	*space;

	if (!(space = (t_vectors *)ft_memalloc((int)sizeof(t_vectors))))
		return (NULL);
	// Being at the center
	space->pos.x = 3;
	space->pos.y = 3;
	space->pos_rad = atan2(space->pos.y, space->pos.x);
	// Watching North
	space->dir.x = 0;
	space->dir.y = 1;
	space->dir_rad = atan2(space->dir.y, space->dir.x);

	return (space);
}

void	ft_recalculate_povs(t_vectors *space)
{
	space->pov_min.x = cos(space->dir_rad + RAD_30);
	space->pov_min.y = sin(space->dir_rad + RAD_30);
	space->pov_min_rad = atan2(space->pov_min.y, space->pov_min.x);
	space->pov_max.x = cos(space->dir_rad - RAD_30);
	space->pov_max.y = sin(space->dir_rad - RAD_30);
	space->pov_max_rad = atan2(space->pov_max.y, space->pov_max.x);

	printf("Min %lf\n", space->pov_min_rad * (180/M_PI));
	printf("Max %lf\n", space->pov_max_rad * (180/M_PI));
}
