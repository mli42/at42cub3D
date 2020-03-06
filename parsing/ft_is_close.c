/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:48:28 by mli               #+#    #+#             */
/*   Updated: 2020/03/06 09:35:07 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_is_close(t_hub *hub, int **map, t_limit *border_x, int max_y)
{
	int i;
	int max_x;
	int prev;

	(void)hub;
	i = 0;
	while (++i < max_y)
	{
		prev = border_x[i - 1].border[1];
		max_x = border_x[i].border[1];
		while (prev < max_x)
			if (map[i][--max_x - 1] != 1)
				return (0);
		while (prev >= max_x)
			if (map[i - 1][--prev] != 1)
				return (0);
	}
	return (1);
}
