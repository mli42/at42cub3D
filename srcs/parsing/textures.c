/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:44:46 by mli               #+#    #+#             */
/*   Updated: 2020/02/06 16:21:33 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		f_ref_s(t_hub *hub, char *str)
{
	int			i;
	int			k;
	static int	pass = 0;

	if (str[1] == 'O' || pass++ > 0)
		return (str[1] == 'O' ? f_ref_so(hub, str) : PASSED_ERROR);
	i = 1;
	ft_pass_spaces(str, &i);
	k = i;
	while (ft_isprint(str[k]) && (str[k] != ' ' || str[k - 1] == '\\'))
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	if ((hub->env->text.sprite.img = mlx_xpm_file_to_image(hub->win->mlx,
	&str[i], &(hub->env->text.sprite.width), &(hub->env->text.sprite.height))))
		hub->env->text.sprite.data = (int *)mlx_get_data_addr(
				hub->env->text.sprite.img, &i, &i, &i);
	return (hub->env->text.sprite.img && hub->env->text.sprite.data ? 1 : -1);
}

int		f_ref_so(t_hub *hub, char *str)
{
	int			i;
	int			k;
	static int	pass = 0;

	if (pass++ > 0)
		return (PASSED_ERROR);
	i = 2;
	ft_pass_spaces(str, &i);
	k = i;
	while (ft_isprint(str[k]) && (str[k] != ' ' || str[k - 1] == '\\'))
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	if ((hub->env->text.south.img = mlx_xpm_file_to_image(hub->win->mlx,
	&str[i], &(hub->env->text.south.width), &(hub->env->text.south.height))))
		hub->env->text.south.data = (int *)mlx_get_data_addr(
				hub->env->text.south.img, &i, &i, &i);
	return (hub->env->text.south.img && hub->env->text.south.data ? 1 : -1);
}

int		f_ref_no(t_hub *hub, char *str)
{
	int			i;
	int			k;
	static int	pass = 0;

	if (str[1] != 'O' || pass++ > 0)
		return (str[1] != 'O' ? -1 : PASSED_ERROR);
	i = 2;
	ft_pass_spaces(str, &i);
	k = i;
	while (ft_isprint(str[k]) && (str[k] != ' ' || str[k - 1] == '\\'))
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	if ((hub->env->text.north.img = mlx_xpm_file_to_image(hub->win->mlx,
	&str[i], &(hub->env->text.north.width), &(hub->env->text.north.height))))
		hub->env->text.north.data = (int *)mlx_get_data_addr(
				hub->env->text.north.img, &i, &i, &i);
	return (hub->env->text.north.img && hub->env->text.north.data ? 1 : -1);
}

int		f_ref_ea(t_hub *hub, char *str)
{
	int			i;
	int			k;
	static int	pass = 0;

	if (str[1] != 'A' || pass++ > 0)
		return (str[1] != 'A' ? -1 : PASSED_ERROR);
	i = 2;
	ft_pass_spaces(str, &i);
	k = i;
	while (ft_isprint(str[k]) && (str[k] != ' ' || str[k - 1] == '\\'))
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	if ((hub->env->text.east.img = mlx_xpm_file_to_image(hub->win->mlx,
	&str[i], &(hub->env->text.east.width), &(hub->env->text.east.height))))
		hub->env->text.east.data = (int *)mlx_get_data_addr(
				hub->env->text.east.img, &i, &i, &i);
	return (hub->env->text.east.img && hub->env->text.east.data ? 1 : -1);
}

int		f_ref_we(t_hub *hub, char *str)
{
	int			i;
	int			k;
	static int	pass = 0;

	if (str[1] != 'E' || pass++ > 0)
		return (str[1] != 'E' ? -1 : PASSED_ERROR);
	i = 2;
	ft_pass_spaces(str, &i);
	k = i;
	while (ft_isprint(str[k]) && (str[k] != ' ' || str[k - 1] == '\\'))
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	if ((hub->env->text.west.img = mlx_xpm_file_to_image(hub->win->mlx,
	&str[i], &(hub->env->text.west.width), &(hub->env->text.west.height))))
		hub->env->text.west.data = (int *)mlx_get_data_addr(
				hub->env->text.west.img, &i, &i, &i);
	return (hub->env->text.west.img && hub->env->text.west.data ? 1 : -1);
}
