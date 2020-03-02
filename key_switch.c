/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:57:03 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 17:05:56 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_press_key(int keycode, void *param)
{
	int				i;
	static int		*keymap = NULL;
	static t_hub	*hub = NULL;

	if (!hub)
		hub = (t_hub *)param;
	if (!keymap)
		keymap = (int *)hub->fct_moves->ref;
	if (keycode == EXIT_CODE)
		exit(ft_remove_all(hub));
	i = -1;
	while (++i < 6)
		if (keycode == keymap[i])
		{
			hub->fct_moves->switch_[i] = 1;
			return (1);
		}
	i--;
	while (++i < 10)
		if (keycode == keymap[i])
		{
			hub->fct_moves->fct[i](hub);
			return (1);
		}
	return (1);
}

int		ft_key_release(int keycode, void *param)
{
	int				i;
	static int		*keymap = NULL;
	static t_hub	*hub = NULL;

	if (!hub || !keymap)
	{
		hub = (t_hub *)param;
		keymap = (int *)hub->fct_moves->ref;
	}
	i = -1;
	while (++i < 8)
		if (keycode == keymap[i])
		{
			hub->fct_moves->switch_[i] = 0;
			break ;
		}
	return (1);
}
