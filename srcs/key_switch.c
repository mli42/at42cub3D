/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:57:03 by mli               #+#    #+#             */
/*   Updated: 2020/03/04 23:19:50 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_which_key(int keycode, int *keymap)
{
	int i;

	i = -1;
	while (++i < FCT_NBR + e_nb_options)
		if (keycode == keymap[i])
			return (i);
	return (-1);
}

int		ft_press_key(int keycode, void *param)
{
	int				i;
	static t_hub	*hub = NULL;

	if (!hub)
		hub = (t_hub *)param;
	if (keycode == EXIT_CODE)
		exit(ft_remove_all(hub));
	if ((i = ft_which_key(keycode, hub->fct_moves->ref)) == -1)
		return (1);
	if (i < FCT_MOVE)
		hub->fct_moves->switch_[i] = 1;
	else if (i < FCT_NBR)
		hub->fct_moves->fct[i](hub);
	else if (i < FCT_NBR + e_nb_options - 1)
		hub->options[i - FCT_NBR] = (hub->options[i - FCT_NBR] == 0);
	return (1);
}

int		ft_key_release(int keycode, void *param)
{
	int				i;
	static t_hub	*hub = NULL;

	if (!hub)
		hub = (t_hub *)param;
	if ((i = ft_which_key(keycode, hub->fct_moves->ref)) == -1)
		return (1);
	if (i < FCT_MOVE)
		hub->fct_moves->switch_[i] = 0;
	return (1);
}
