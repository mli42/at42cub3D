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
	// Watching North
	space->dir.x = 0;
	space->dir.y = 1;

	return (space);
}

void	ft_recalculate_povs(t_vectors *space)
{
	double dir_rad;

//	printf("Step: %d\n", i++);
	dir_rad = atan2(space->dir.y, space->dir.x);
//	printf("dir_rad : %lf\n", dir_rad);

	space->pov_min.x = cos(dir_rad - RAD_30);
	space->pov_min.y = sin(dir_rad - RAD_30);

	space->pov_max.x = cos(dir_rad + RAD_30);
	space->pov_max.y = sin(dir_rad + RAD_30);

//	printf("Min %lf\n", atan2(space->pov_min.y, space->pov_min.x) * (180/M_PI));
//	printf("Max %lf\n", atan2(space->pov_max.y, space->pov_max.x) * (180/M_PI));
}
