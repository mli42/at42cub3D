/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allve_been_called.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 23:51:16 by mli               #+#    #+#             */
/*   Updated: 2020/01/26 18:26:37 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_allve_been_called(t_hub *hub)
{
	if (f_ref_resolution(hub, "R error ?") != PASSED_ERROR)
		return (-1);
	if (f_ref_floor(hub, "F error ?") != PASSED_ERROR)
		return (-1);
	if (f_ref_ceiling(hub, "C error ?") != PASSED_ERROR)
		return (-1);
	if (f_ref_s(hub, "S ") != PASSED_ERROR)
		return (-1);
	if (f_ref_so(hub, "SO ") != PASSED_ERROR)
		return (-1);
	if (f_ref_no(hub, "NO ") != PASSED_ERROR)
		return (-1);
	if (f_ref_we(hub, "WE ") != PASSED_ERROR)
		return (-1);
	if (f_ref_ea(hub, "EA ") != PASSED_ERROR)
		return (-1);
	return (1);
}
