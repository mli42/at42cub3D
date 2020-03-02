/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:44:24 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 16:20:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AFFINE_H
# define FT_AFFINE_H

typedef struct	s_dr_sp
{
    int size;
    int start;
    int end;
}				t_dr_sp;

double			ft_points_dist(t_coord a, t_coord b);
double			ft_dist_to_sp(t_coord my_pos, t_coord sp_pos);
int				same_pos(t_coord a, t_coord b);
double			ft_find_b(t_coord a, double ax);
double			ft_sp_offset(t_sp sprite, t_faffine perp, t_coord m);

t_faffine		ft_perpf(t_faffine dir, t_coord point);
t_faffine		ft_dirf(t_coord a, t_coord b);
t_faffine		ft_castf(double ray, t_coord a);
t_coord			resolve_eq(t_faffine perp, t_faffine cast);
double			ft_affine(t_faffine fct, double x);
void			ft_sprite_next(t_hub *hub, t_sp sp);

t_coord			v_add(t_coord a, t_coord b);
t_coord			v_sub(t_coord a, t_coord b);
t_coord			v_scal(t_coord a, double b);

#endif
