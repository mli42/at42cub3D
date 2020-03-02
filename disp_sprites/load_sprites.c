/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:48:36 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 16:49:39 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_sprites(t_hub *hub, int **map, int *width, int height)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (++i < height - 1)
	{
		j = 0;
		while (++j < width[i] - 1)
		{
			if (map[i][j] == 2)
				hub->env->sp[k++].center = (t_coord){j + 0.5, i + 0.5};
		}
	}
}
