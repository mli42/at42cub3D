/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:09:34 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 14:25:39 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ft_affine.h"

typedef	struct	s_dr_sp
{
	int size;
	int start;
	int end;
}				t_dr_sp;

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
	int		h;
	t_dr_sp	sp_h;

	h = ft_abs_double((int)(hub->win->win_size[1] / trans.y));
	sp_h.start = -h / 2 + hub->win->win_size[1] / 2;
	if (sp_h.start < 0)
		sp_h.start = 0;
	sp_h.end = h / 2 + hub->win->win_size[1] / 2;
	if (sp_h.end >= hub->win->win_size[1])
		sp_h.end = hub->win->win_size[1] - 1;
	sp_h.size = h;
	return (sp_h);
}

t_dr_sp	ft_sp_w(t_hub *hub, t_coord trans, int screen_x)
{
	int		width;
	t_dr_sp	sp_w;


	width = ft_abs_double((int)(hub->win->win_size[1] / trans.y));
	sp_w.start = -width / 2 + screen_x;
	if (sp_w.start < 0)
		sp_w.start = 0;
	sp_w.end = width / 2 + screen_x;
	if ((sp_w.end >= (signed)hub->win->win_size[0]))
		sp_w.end = hub->win->win_size[0] - 1;
	sp_w.size = width;
	return (sp_w);
}

void	draw_h(t_hub *hub, int sp_w_start, t_dr_sp sp_h, int text_x)
{
	int text_y;
	int color;


	while (sp_h.start < sp_h.end)
	{
		text_y = sp_h.start - (hub->win->win_size[1] / 2) + sp_h.size / 2;
		text_y = text_y * hub->env->text.sprite.height / sp_h.size;
		color = hub->env->text.sprite.data[text_x +
			text_y * hub->env->text.sprite.width];
		if (color != -16777216 && color != 9961608)
		hub->win->img_data[sp_w_start +
			sp_h.start * hub->win->win_size[0]] = color;
		sp_h.start++;
	}
	(void)color;
	(void)hub;
	(void)sp_w_start;
	(void)sp_h;
}

void    ft_sprite_next(t_hub *hub, int i, t_sp sp, double ray)
{
	t_coord		sp_coord;
	t_coord		trans;

	sp_coord = v_sub(sp.center, hub->player->entity.pos);
	trans = ft_transform(hub, sp_coord);


	int screen_x;
	t_dr_sp sp_h;
	t_dr_sp sp_w;

	screen_x = (int)((hub->win->win_size[0] / 2) * (1 + trans.x / trans.y));
	sp_h = ft_sp_h(hub, trans);
	sp_w = ft_sp_w(hub, trans, screen_x);

	int text_x;

	while (sp_w.start < sp_w.end)
	{
		text_x = (int)((sp_w.start - (-sp_w.size / 2 + screen_x)) *
				hub->env->text.sprite.width / sp_w.size);
		if (trans.y > 0 && sp_w.start > 0 &&
			sp_w.start < hub->win->win_size[0] && trans.y < sp.distance)
			draw_h(hub, sp_w.start, sp_h, text_x);
		sp_w.start++;
	}
	(void)hub;
	(void)sp;
	(void)i;
	(void)ray;
}




