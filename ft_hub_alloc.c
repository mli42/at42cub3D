/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hub_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 00:23:18 by mli               #+#    #+#             */
/*   Updated: 2020/01/26 15:25:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_hub		*ft_hub_alloc(void)
{
	t_hub *hub;

	if (!(hub = (t_hub *)ft_memalloc(sizeof(t_hub))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->win = (t_win *)ft_memalloc(sizeof(t_win))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->player = (t_player *)ft_memalloc(sizeof(t_player))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->fct_moves = fct_moves_ptr_init()))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->env = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(ft_error("Can't allocate", hub));
	return (hub);
}
