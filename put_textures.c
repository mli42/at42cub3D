/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:36:19 by mli               #+#    #+#             */
/*   Updated: 2020/02/04 22:41:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_north(t_hub * hub, t_walls walls, float y[4], float x)
{
	int		pixel;

	if (y[0] == -1  || y[0] >= x * hub->env->text.north.height)
		y[0] = x * (float)hub->env->text.north.height / (float)walls.size;
	pixel = hub->env->text.north.data[
		(int)(((int)y[0]) * hub->env->text.north.height +
			(fmod(walls.check_pt.x + 1, 1)) * hub->env->text.north.width)];
	y[0] += (float)hub->env->text.north.height / (float)walls.size;
	return (pixel);
}

int		is_south(t_hub * hub, t_walls walls, float y[4], float x)
{
	int		pixel;

	if (y[1] == -1  || y[1] >= x * hub->env->text.south.height)
		y[1] = x * (float)hub->env->text.south.height / (float)walls.size;
	pixel = hub->env->text.south.data[
		(int)(((int)y[1]) * hub->env->text.south.height +
			(1 - fmod(walls.check_pt.x + 1, 1)) * hub->env->text.south.width)];
	y[1] += (float)hub->env->text.south.height / (float)walls.size;
	return (pixel);
}

int		is_west(t_hub * hub, t_walls walls, float y[4], float x)
{
	int		pixel;

	if (y[2] == -1  || y[2] >= x * hub->env->text.west.height)
		y[2] = x * (float)hub->env->text.west.height / (float)walls.size;
	pixel = hub->env->text.west.data[
		(int)(((int)y[2]) * hub->env->text.west.height +
			(1 - fmod(walls.check_pt.y + 1, 1)) * hub->env->text.west.width)];
	y[2] += (float)hub->env->text.west.height / (float)walls.size;
	return (pixel);
}

int		is_east(t_hub * hub, t_walls walls, float y[4], float x)
{
	int		pixel;

	if (y[3] == -1  || y[3] >= x * hub->env->text.east.height)
		y[3] = x * (float)hub->env->text.east.height / (float)walls.size;
	pixel = hub->env->text.east.data[
		(int)(((int)y[3]) * hub->env->text.east.height +
			(fmod(walls.check_pt.y + 1, 1)) * hub->env->text.east.width)];
	y[3] += (float)hub->env->text.east.height / (float)walls.size;
	return (pixel);
}

