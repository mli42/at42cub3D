/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:36:19 by mli               #+#    #+#             */
/*   Updated: 2020/02/11 19:36:41 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_north(t_data texture, t_walls walls, float y)
{
	return (texture.data[(int)(((int)y) * texture.height +
		(fmod(walls.check_pt.x + 1, 1)) * texture.width)]);
}

int		is_south(t_data texture, t_walls walls, float y)
{
	return (texture.data[(int)(((int)y) * texture.height +
		(1 - fmod(walls.check_pt.x + 1, 1)) * texture.width)]);
}

int		is_west(t_data texture, t_walls walls, float y)
{
	return (texture.data[(int)(((int)y) * texture.height +
		(1 - fmod(walls.check_pt.y + 1, 1)) * texture.width)]);
}

int		is_east(t_data texture, t_walls walls, float y)
{
	return (texture.data[(int)(((int)y) * texture.height +
		(fmod(walls.check_pt.y + 1, 1)) * texture.width)]);
}
