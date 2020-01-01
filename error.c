/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:00:25 by mli               #+#    #+#             */
/*   Updated: 2020/01/01 17:53:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error(char *str, t_param *hub)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	ft_remove_all(hub);
	return (-1);
}

t_vectors	*ft_init_space(void)
{
	t_vectors	*space;

	if (!(space = (t_vectors *)ft_memalloc((int)sizeof(t_vectors))))
		return (NULL);
	// Being at the center
	space->pos.x = 3.5;
	space->pos.y = 3.5;
	// Watching North
	space->dir.x = 0;
	space->dir.y = -1;

	return (space);
}

void	ft_recalculate_povs(t_vectors *space)
{
	// To move/re-add when i'll change my position => have to recalculate this rad
	space->pos_rad = atan2(space->pos.y, space->pos.x);

	space->dir_rad = atan2(space->dir.y, space->dir.x);
	space->pov_min.x = cos(space->dir_rad + RAD_30);
	space->pov_min.y = sin(space->dir_rad + RAD_30);
	space->pov_min_rad = atan2(space->pov_min.y, space->pov_min.x);
//	if (space->pov_min_rad < 0)
//		space->pov_min_rad += PI2;
	space->pov_max.x = cos(space->dir_rad - RAD_30);
	space->pov_max.y = sin(space->dir_rad - RAD_30);
	space->pov_max_rad = atan2(space->pov_max.y, space->pov_max.x);
//	if (space->pov_max_rad < 0)
//		space->pov_max_rad += PI2;

/*	printf("\n");
	printf("Min %lf\n", space->pov_min_rad * (180/M_PI));
	printf("Min rad %lf\n", space->pov_min_rad);
	printf("\n");
	printf("Max %lf\n", space->pov_max_rad * (180/M_PI));
	printf("Max rad %lf\n", space->pov_max_rad);
	*/
}
