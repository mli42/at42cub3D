/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:44:24 by mli               #+#    #+#             */
/*   Updated: 2020/02/21 11:23:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AFFINE_H
# define FT_AFFINE_H

double		ft_points_dist(t_coord a, t_coord b);
double		ft_dist_to_sp(t_coord my_pos, t_coord sp_pos);
int			same_pos(t_coord a, t_coord b);
double		ft_sp_offset(t_sp sprite, double ray);
double		ft_find_b(t_coord a, double ax);

t_faffine	ft_perpf(t_faffine dir, t_coord point);
t_faffine	ft_dirf(t_coord a, t_coord b);
t_faffine	ft_castf(double ray, t_coord a);
t_coord		resolve_eq(t_faffine perp, t_faffine cast);

#endif
