/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:02:00 by mli               #+#    #+#             */
/*   Updated: 2020/01/27 22:28:14 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_empty_win(t_win *win)
{
	if (win->mlx && win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx && win->img)
		mlx_destroy_image(win->mlx, win->img);
	ft_free((void **)&win);
}

void	ft_empty_env(t_hub *hub)
{
	int i;

	i = 0;
	while (i < hub->env->map_height)
		ft_free((void **)(&(hub->env->map[i++])));
	ft_free((void **)(&hub->env->map));
	if (hub->env->text.north.img)
		mlx_destroy_image(hub->win->mlx, hub->env->text.north.img);
	if (hub->env->text.south.img)
		mlx_destroy_image(hub->win->mlx, hub->env->text.south.img);
	if (hub->env->text.west.img)
		mlx_destroy_image(hub->win->mlx, hub->env->text.west.img);
	if (hub->env->text.east.img)
		mlx_destroy_image(hub->win->mlx, hub->env->text.east.img);
	if (hub->env->text.sprite.img)
		mlx_destroy_image(hub->win->mlx, hub->env->text.sprite.img);
	ft_free((void **)(&hub->env));
}

int		ft_remove_all(t_hub *hub)
{
	if (hub != NULL)
	{
		if (hub->env)
			ft_empty_env(hub);
		if (hub->win)
			ft_empty_win(hub->win);
		ft_free((void **)&hub->player);
		if (hub->fct_moves)
		{
			ft_free((void **)&hub->fct_moves->ref);
			ft_free((void **)&hub->fct_moves->fct);
			ft_free((void **)&hub->fct_moves);
		}
	}
	ft_free((void **)&hub);
	write(1, "Process stoped.\n", 16);
	return (1);
}
