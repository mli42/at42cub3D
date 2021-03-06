/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:27 by mli               #+#    #+#             */
/*   Updated: 2020/03/17 16:57:01 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_abs_lf(double nbr)
{
	return ((nbr >= 0 ? nbr : -nbr));
}

long int	ft_abs_ld(long int nb)
{
	return ((nb >= 0 ? nb : -nb));
}
