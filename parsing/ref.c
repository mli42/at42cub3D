/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 17:00:42 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		f_ref_ceiling(t_hub *hub, char *str)
{
	int				i;
	int				k;
	int				nbr[3];
	static int		pass = 0;
	unsigned char	*color_bit;

	if (pass++ > 0)
		return (PASSED_ERROR);
	i = 1;
	hub->env->ceiling_color = 0;
	color_bit = (unsigned char *)(&(hub->env->ceiling_color));
	k = 3;
	while (--k >= 0)
	{
		nbr[k] = ft_atoi_ptr(str, &i);
		ft_pass_spaces(str, &i);
		if ((nbr[k] < 0 || nbr[k] > 255) || (k > 0 && str[i++] != ','))
			return (-1);
		color_bit[k] = nbr[k];
	}
	ft_pass_spaces(str, &i);
	return ((str[i] == '\0' ? 1 : -1));
}

int		f_ref_floor(t_hub *hub, char *str)
{
	int				i;
	int				k;
	int				nbr[3];
	static int		pass = 0;
	unsigned char	*color_bit;

	if (pass++ > 0)
		return (PASSED_ERROR);
	i = 1;
	hub->env->floor_color = 0;
	color_bit = (unsigned char *)(&(hub->env->floor_color));
	k = 3;
	while (--k >= 0)
	{
		nbr[k] = ft_atoi_ptr(str, &i);
		ft_pass_spaces(str, &i);
		if ((nbr[k] < 0 || nbr[k] > 255) || (k > 0 && str[i++] != ','))
			return (-1);
		color_bit[k] = nbr[k];
	}
	ft_pass_spaces(str, &i);
	return ((str[i] == '\0' ? 1 : -1));
}

int		f_ref_resolution(t_hub *hub, char *str)
{
	int			i;
	int			nbr[2];
	static int	pass = 0;

	if (pass++ > 0)
		return (PASSED_ERROR);
	i = 1;
	nbr[0] = ft_atoi_ptr(str, &i);
	nbr[1] = ft_atoi_ptr(str, &i);
	hub->win->win_size[0] = (nbr[0] > WIN_X_MAX ? WIN_X_MAX : nbr[0]);
	hub->win->win_size[1] = (nbr[1] > WIN_Y_MAX ? WIN_Y_MAX : nbr[1]);
	ft_pass_spaces(str, &i);
	if (str[i] != '\0' || nbr[0] <= 0 || nbr[1] <= 0)
		return (-1);
	return (1);
}

t_fct_r	*ft_ref_parse(void)
{
	t_fct_r		*ref_parse;
	const char	*ref = "RFCSNWE";

	if (!(ref_parse = (t_fct_r *)ft_memalloc(sizeof(t_fct_r))))
		return (NULL);
	if (!(ref_parse->fct = (int (**)())ft_memalloc(sizeof(int (*)()) * 7)))
		return (NULL);
	ref_parse->fct[0] = f_ref_resolution;
	ref_parse->fct[1] = f_ref_floor;
	ref_parse->fct[2] = f_ref_ceiling;
	ref_parse->fct[3] = f_ref_s;
	ref_parse->fct[4] = f_ref_no;
	ref_parse->fct[5] = f_ref_we;
	ref_parse->fct[6] = f_ref_ea;
	ref_parse->ref = ref;
	return (ref_parse);
}
