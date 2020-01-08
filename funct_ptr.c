/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2020/01/08 22:57:19 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_arrow_right(t_param *hub)
{
	hub->space->dir.x = cos(hub->space->dir_rad + RAD_5);
	hub->space->dir.y = sin(hub->space->dir_rad + RAD_5);
}

void	ft_arrow_left(t_param *hub)
{
	hub->space->dir.x = cos(hub->space->dir_rad - RAD_5);
	hub->space->dir.y = sin(hub->space->dir_rad - RAD_5);
}

void	ft_arrow_up(t_param *hub)
{
	(void)hub;
}

void	ft_arrow_down(t_param *hub)
{
	(void)hub;
}

void	ft_w_key(t_param *hub)
{
	hub->space->pos.y += (hub->space->dir.y * FOOT_STEP * 2);
	hub->space->pos.x += (hub->space->dir.x * FOOT_STEP * 2);
}

void	ft_s_key(t_param *hub)
{
	hub->space->pos.y -= (hub->space->dir.y * FOOT_STEP * 2);
	hub->space->pos.x -= (hub->space->dir.x * FOOT_STEP * 2);
}

void	ft_a_key(t_param *hub)
{
	t_coord left_side;
	double left_rad;

	left_rad = atan2(hub->space->dir.y, hub->space->dir.x) - RAD_90;
	left_side.x = cos(left_rad);
	left_side.y = sin(left_rad);

	hub->space->pos.y += (left_side.y * FOOT_STEP);
	hub->space->pos.x += (left_side.x * FOOT_STEP);
}

void	ft_d_key(t_param *hub)
{
	t_coord right_side;
	double right_rad;

	right_rad = atan2(hub->space->dir.y, hub->space->dir.x) + RAD_90;
	right_side.x = cos(right_rad);
	right_side.y = sin(right_rad);

	hub->space->pos.y += (right_side.y * FOOT_STEP);
	hub->space->pos.x += (right_side.x * FOOT_STEP);
}

t_funct		*funct_ptr_init(void)
{
	t_funct *funct;

	if (!(funct = (t_funct *)ft_memalloc(sizeof(t_funct))))
		return (NULL);
	funct->key_map[0] = ARROW_RIGHT;
	funct->key_map[1] = ARROW_LEFT;
	funct->key_map[2] = ARROW_UP;
	funct->key_map[3] = ARROW_DOWN;
	funct->key_map[4] = A_KEY;
	funct->key_map[5] = S_KEY;
	funct->key_map[6] = D_KEY;
	funct->key_map[7] = W_KEY;
	funct->fct[0] = ft_arrow_right;
	funct->fct[1] = ft_arrow_left;
	funct->fct[2] = ft_arrow_up;
	funct->fct[3] = ft_arrow_down;
	funct->fct[4] = ft_a_key;
	funct->fct[5] = ft_s_key;
	funct->fct[6] = ft_d_key;
	funct->fct[7] = ft_w_key;
	return (funct);
}
