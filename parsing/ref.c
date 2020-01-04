/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/01/05 00:13:37 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		f_ref_ceiling(t_param *hub, char *str)
{
	int				i;
	int				k;
	int				nbr[3];
	static int		pass = 0;
	unsigned char	*color_bit;

	if (pass++ > 0)
		return (PASSED_ERROR);
	i = 1;
	hub->parse->ceiling_color = 0;
	color_bit = (unsigned char *)(&(hub->parse->ceiling_color));
	k = 3;
	while (--k >= 0)
	{
		nbr[k] = ft_atoi_ptr(str, &i);
		ft_pass_spaces(str, &i);
		if ((nbr[k] < 0 || nbr[k] > 255) || (k > 0 && str[i++] != ','))
			return (-1);
		color_bit[k] = nbr[k];
	}
	printf("Ceiling : R %d | G %d | B %d\n", nbr[2], nbr[1], nbr[0]);
	ft_pass_spaces(str, &i);
	return ((str[i] == '\0' ? 1 : -1));
}

int		f_ref_floor(t_param *hub, char *str)
{
	int				i;
	int				k;
	int				nbr[3];
	static int		pass = 0;
	unsigned char	*color_bit;

	if (pass++ > 0)
		return (PASSED_ERROR);
	i = 1;
	hub->parse->floor_color = 0;
	color_bit = (unsigned char *)(&(hub->parse->floor_color));
	k = 3;
	while (--k >= 0)
	{
		nbr[k] = ft_atoi_ptr(str, &i);
		ft_pass_spaces(str, &i);
		if ((nbr[k] < 0 || nbr[k] > 255) || (k > 0 && str[i++] != ','))
			return (-1);
		color_bit[k] = nbr[k];
	}
	printf("Floor : R %d | G %d | B %d\n", nbr[2], nbr[1], nbr[0]);
	ft_pass_spaces(str, &i);
	return ((str[i] == '\0' ? 1 : -1));
}

int		f_ref_resolution(t_param *hub, char *str)
{
	int			i;
	int			nbr[2];
	static int	pass = 0;

	if (pass++ > 0)
		return (PASSED_ERROR);
	i = 1;
	nbr[0] = ft_atoi_ptr(str, &i);
	nbr[1] = ft_atoi_ptr(str, &i);
	printf("Recognized R: %d, %d\n", (nbr[0] > WIN_X_MAX ? WIN_X_MAX : nbr[0]),
		(nbr[1] > WIN_Y_MAX ? WIN_Y_MAX : nbr[1]));

	(void)hub;
	/*
	 * hub->draw->win_size[0] = (nbr[0] > WIN_X_MAX ? WIN_X_MAX : nbr[0]);
	 * hub->draw->win_size[1] = (nbr[1] > WIN_Y_MAX ? WIN_Y_MAX : nbr[1]);
	 */

	ft_pass_spaces(str, &i);
	if (str[i] != '\0' || nbr[0] <= 0 || nbr[1] <= 0)
		return (-1);
	return (1);
}

t_ref		ft_ref_parse(void)
{
	t_ref	ref_parse;

	ref_parse.ref[0] = "R"; 
	ref_parse.ref[1] = "F"; 
	ref_parse.ref[2] = "C"; 
	ref_parse.ref[3] = "S"; 
	ref_parse.ref[4] = "N"; 
	ref_parse.ref[5] = "W"; 
	ref_parse.ref[6] = "E"; 
	ref_parse.f_ref[0] = f_ref_resolution; 
	ref_parse.f_ref[1] = f_ref_floor; 
	ref_parse.f_ref[2] = f_ref_ceiling; 
	ref_parse.f_ref[3] = f_ref_s; 
	ref_parse.f_ref[4] = f_ref_no; 
	ref_parse.f_ref[5] = f_ref_we; 
	ref_parse.f_ref[6] = f_ref_ea; 

	return (ref_parse);
}
