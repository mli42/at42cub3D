/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:36:19 by mli               #+#    #+#             */
/*   Updated: 2020/03/18 15:31:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	ft_which_text(t_hub *hub, t_walls walls)
{
	if (walls.face == 'N')
		return (hub->env->text.north);
	else if (walls.face == 'E')
		return (hub->env->text.east);
	else if (walls.face == 'S')
		return (hub->env->text.south);
	return (hub->env->text.west);
}

void	ft_black_ray(t_hub *hub, int i)
{
	int		x;

	x = -1;
	while (++x < hub->win->win_size[1])
		hub->win->img_data[x * hub->win->win_size[0] + i] = 0;
}

int		ft_face(double current_ray, int h_v)
{
	if (current_ray < 0)
		current_ray += PI2;
	if (current_ray >= 0 && current_ray <= M_PI && h_v == 'h')
		return ('S');
	if (current_ray >= M_PI && current_ray <= PI2 && h_v == 'h')
		return ('N');
	if (current_ray >= M_PI / 2 && current_ray <= 3 * M_PI / 2 && h_v == 'v')
		return ('W');
	return ('E');
}

int		ft_darker(char light, int pixel, float distance)
{
	distance /= 3;
	if (light == 0 || distance <= 1)
		return (pixel);
	pixel = ((int)(((pixel & 0xFF0000) >> 16) / distance) << 16) +
		((int)(((pixel & 0x00FF00) >> 8) / distance) << 8) +
		(int)((pixel & 0x0000FF) / distance);
	return (pixel);
}
