/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 23:48:53 by mli               #+#    #+#             */
/*   Updated: 2020/01/08 23:56:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mouse_press(int button, int x, int y, void *param)
{
	t_param		*hub;

	hub = (t_param *)param;
	printf("Button pressed: %d, where : [%d][%d]\n", button, x, y);

	return (1);
}
