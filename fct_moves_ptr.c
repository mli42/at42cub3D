/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_moves_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2020/03/04 17:07:37 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_arrow_right(t_hub *hub)
{
	if (hub->player->entity.speed <= FOOT_STEP + 0.001)
	{
		hub->player->entity.dir.x = cos(hub->player->entity.dir_rad + RAD_2_5);
		hub->player->entity.dir.y = sin(hub->player->entity.dir_rad + RAD_2_5);
	}
	else
	{
		hub->player->entity.dir.x = cos(hub->player->entity.dir_rad + RAD_5);
		hub->player->entity.dir.y = sin(hub->player->entity.dir_rad + RAD_5);
	}
}

void	ft_arrow_left(t_hub *hub)
{
	if (hub->player->entity.speed <= FOOT_STEP + 0.001)
	{
		hub->player->entity.dir.x = cos(hub->player->entity.dir_rad - RAD_2_5);
		hub->player->entity.dir.y = sin(hub->player->entity.dir_rad - RAD_2_5);
	}
	else
	{
		hub->player->entity.dir.x = cos(hub->player->entity.dir_rad - RAD_5);
		hub->player->entity.dir.y = sin(hub->player->entity.dir_rad - RAD_5);
	}
}

t_funct	*fct_moves_ptr_init(void)
{
	t_funct		*funct;
	const int	nb = FCT_NBR;

	if (!(funct = (t_funct *)ft_memalloc(sizeof(t_funct))) ||
			!(funct->ref = (int *)ft_memalloc(sizeof(int) * nb)) ||
			!(funct->switch_ = (char *)ft_memalloc(sizeof(char) * nb)) ||
			!(funct->fct = (void (**)())ft_memalloc(sizeof(void (*)()) * nb)))
		return (NULL);
	ft_memcpy(funct->ref, (int	[]){ARROW_RIGHT, ARROW_LEFT, A_KEY, S_KEY,
		D_KEY, W_KEY, SHIFT_KEY, C_KEY, R_KEY, P_KEY, SPACE_KEY, O_KEY},
		sizeof(int) * nb);
	ft_memcpy(funct->fct, (void	(*[])()){ft_arrow_right, ft_arrow_left,
		ft_a_key, ft_s_key, ft_d_key, ft_w_key, ft_speed, ft_collision,
		ft_restart_game, ft_save, ft_activate_all_opt, ft_sprite_state},
		sizeof(void (*)()) * nb);
	return (funct);
}
