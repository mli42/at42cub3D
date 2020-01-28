/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_moves_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2020/01/28 16:56:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_arrow_right(t_hub *hub)
{
	hub->player->entity.dir.x = cos(hub->player->entity.dir_rad + RAD_5);
	hub->player->entity.dir.y = sin(hub->player->entity.dir_rad + RAD_5);
}

void	ft_arrow_left(t_hub *hub)
{
	hub->player->entity.dir.x = cos(hub->player->entity.dir_rad - RAD_5);
	hub->player->entity.dir.y = sin(hub->player->entity.dir_rad - RAD_5);
}

void	ft_arrow_up(t_hub *hub)
{
	(void)hub;
}

void	ft_arrow_down(t_hub *hub)
{
	(void)hub;
}

t_funct	*fct_moves_ptr_init(void)
{
	t_funct *funct;

	if (!(funct = (t_funct *)ft_memalloc(sizeof(t_funct))) ||
			!(funct->ref = (int *)ft_memalloc(sizeof(int) * 8)) ||
			!(funct->fct = (void (**)())ft_memalloc(sizeof(void (*)()) * 8)))
		return (NULL);
	funct->ref[0] = ARROW_RIGHT;
	funct->ref[1] = ARROW_LEFT;
	funct->ref[2] = ARROW_UP;
	funct->ref[3] = ARROW_DOWN;
	funct->ref[4] = A_KEY;
	funct->ref[5] = S_KEY;
	funct->ref[6] = D_KEY;
	funct->ref[7] = W_KEY;
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
