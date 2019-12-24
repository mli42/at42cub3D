/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:23:56 by mli               #+#    #+#             */
/*   Updated: 2019/12/25 00:17:07 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_arrow_right(t_param *hub)
{
	hub->space->dir.x = cos(hub->space->dir_rad + RAD_5);
	hub->space->dir.y = sin(hub->space->dir_rad + RAD_5);
	printf("Pressed ARROW_RIGHT\n");
}

void	ft_arrow_left(t_param *hub)
{
	hub->space->dir.x = cos(hub->space->dir_rad - RAD_5);
	hub->space->dir.y = sin(hub->space->dir_rad - RAD_5);
	printf("Pressed ARROW_LEFT\n");
}

void	ft_arrow_up(t_param *hub)
{
	(void)hub;
	printf("Pressed ARROW_UP\n");
}

void	ft_arrow_down(t_param *hub)
{
	(void)hub;
	printf("Pressed ARROW_DOWN\n");
}

void	ft_a_key(t_param *hub)
{
	(void)hub;
	printf("Pressed A-key\n");
}

void	ft_s_key(t_param *hub)
{
	(void)hub;
	printf("Pressed S-key\n");
}

void	ft_d_key(t_param *hub)
{
	(void)hub;
	printf("Pressed D-key\n");
}

void	ft_w_key(t_param *hub)
{
	(void)hub;
	printf("Pressed W-key\n");
}

t_funct		*funct_ptr_init(void)
{
	t_funct *funct;

	if (!(funct = (t_funct *)ft_memalloc((int)sizeof(t_funct))))
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
