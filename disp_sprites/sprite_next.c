/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:09:34 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 16:28:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

t_coord	ft_transform(t_hub *hub, t_coord sp_coord)
{
	t_coord trans;
	double	inv;

	inv = 1.0 / (hub->plane.x * hub->player->entity.dir.y - hub->plane.y *
			hub->player->entity.dir.x);
	trans.x = inv * (hub->player->entity.dir.y * sp_coord.x - sp_coord.y *
			hub->player->entity.dir.x);
	trans.y = inv * (-hub->plane.y * sp_coord.x + hub->plane.x * sp_coord.y);
	return (trans);
}

t_dr_sp	ft_sp_h(t_hub *hub, t_coord trans)
{
	t_dr_sp	sp_h;

	sp_h.size = ft_abs_double((int)(hub->win->win_size[1] / trans.y));
	if ((sp_h.start = (hub->win->win_size[1] - sp_h.size) >> 1) < 0)
		sp_h.start = 0;
	if ((sp_h.end = (sp_h.size +
					hub->win->win_size[1]) >> 1) >= hub->win->win_size[1])
		sp_h.end = hub->win->win_size[1] - 1;
	return (sp_h);
}

t_dr_sp	ft_sp_w(t_hub *hub, t_coord trans, int screen_x)
{
	t_dr_sp	sp_w;

	sp_w.size = ft_abs_double((int)(hub->win->win_size[1] / trans.y));
	if ((sp_w.start = (-sp_w.size >> 1) + screen_x) < 0)
		sp_w.start = 0;
	if ((sp_w.end = (sp_w.size >> 1) + screen_x) >= hub->win->win_size[0])
		sp_w.end = hub->win->win_size[0] - 1;
	return (sp_w);
}

void	draw_h(t_hub *hub, int x, t_dr_sp sp_h, int text_x)
{
	int		color;
	float	text_y;

	while (sp_h.start < sp_h.end)
	{
		text_y = sp_h.start + ((sp_h.size - hub->win->win_size[1]) >> 1);
		text_y *= ((float)hub->env->text.sprite.height / sp_h.size);
		color = hub->env->text.sprite.data[text_x +
			(int)text_y * hub->env->text.sprite.width];
		if (color != -16777216 && color != 9961608)
			hub->win->img_data[sp_h.start * hub->win->win_size[0] + x] = color;
		sp_h.start++;
	}
}

void	ft_sprite_next(t_hub *hub, t_sp sp)
{
	int		text_x;
	int		screen_x;
	t_dr_sp	sp_h;
	t_dr_sp	sp_w;
	t_coord	trans;

	trans = ft_transform(hub, v_sub(sp.center, hub->player->entity.pos));
	if (trans.y < 0 || trans.y > sp.distance)
		return ;
	screen_x = (int)((hub->win->win_size[0] >> 1) * (1 + trans.x / trans.y));
	if ((sp_w = ft_sp_w(hub, trans, screen_x)).start < 0 ||
		sp_w.start > hub->win->win_size[0])
		return ;
	sp_h = ft_sp_h(hub, trans);
	while (sp_w.start < sp_w.end)
	{
		text_x = (int)((sp_w.start - (-sp_w.size / 2 + screen_x)) *
				hub->env->text.sprite.width / sp_w.size);
		draw_h(hub, sp_w.start, sp_h, text_x);
		sp_w.start++;
	}
}
