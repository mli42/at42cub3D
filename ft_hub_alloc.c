/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hub_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 00:23:18 by mli               #+#    #+#             */
/*   Updated: 2020/01/05 13:17:25 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_param		*ft_hub_alloc(void)
{
	t_param *hub;

	if (!(hub = (t_param *)ft_memalloc(sizeof(t_param))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->draw = (t_win *)ft_memalloc(sizeof(t_win))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->space = (t_vectors *)ft_memalloc(sizeof(t_vectors))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->funct = funct_ptr_init()))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->parse = (t_parsing *)ft_memalloc(sizeof(t_parsing))))
		exit(ft_error("Can't allocate", hub));
	if (!(hub->parse->txt_w = (t_fd *)ft_memalloc(sizeof(t_fd))))
		exit(ft_error("Can't allocate", hub));
	return (hub);
}
