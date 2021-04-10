/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:44:24 by mli               #+#    #+#             */
/*   Updated: 2020/03/03 17:21:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AFFINE_H
# define FT_AFFINE_H

double		ft_points_dist(t_coord a, t_coord b);
int			same_pos(t_coord a, t_coord b);
double		ft_find_b(t_coord a, double ax);
double		ft_sp_offset(t_hub *hub, t_sp sprite);

t_faffine	ft_perpf(t_faffine dir, t_coord point);
t_faffine	ft_dirf(t_coord a, t_coord b);
t_faffine	ft_castf(double ray, t_coord a);

t_coord		resolve_eq(t_faffine perp, t_faffine cast);
double		ft_affine(t_faffine fct, double x);

#endif
