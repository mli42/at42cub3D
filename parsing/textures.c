/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:44:46 by mli               #+#    #+#             */
/*   Updated: 2020/02/04 16:05:01 by mli              ###   ########.fr       */
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
	while (ft_isprint(str[k]) && str[k] != ' ')
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	hub->env->text.sprite.img = mlx_xpm_file_to_image(hub->win->mlx, &str[i],
			&(hub->env->text.sprite.width), &(hub->env->text.sprite.height));
	// Do not forget to protect
	hub->env->text.sprite.data = (int *)mlx_get_data_addr(hub->env->text.sprite.img,
			&i, &i, &i);
	return (hub->env->text.sprite.img ? 1 : -1);
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
	while (ft_isprint(str[k]) && str[k] != ' ')
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	hub->env->text.south.img = mlx_xpm_file_to_image(hub->win->mlx, &str[i],
			&(hub->env->text.south.width), &(hub->env->text.south.height));
	// Do not forget to protect
	hub->env->text.south.data = (int *)mlx_get_data_addr(hub->env->text.south.img,
			&i, &i, &i);
	return (hub->env->text.south.img ? 1 : -1);
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
	while (ft_isprint(str[k]) && str[k] != ' ')
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	hub->env->text.north.img = mlx_xpm_file_to_image(hub->win->mlx, &str[i],
			&(hub->env->text.north.width), &(hub->env->text.north.height));
	// Do not forget to protect
	hub->env->text.north.data = (int *)mlx_get_data_addr(hub->env->text.north.img,
			&i, &i, &i);
	return (hub->env->text.north.img ? 1 : -1);
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
	while (ft_isprint(str[k]) && str[k] != ' ')
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	hub->env->text.east.img = mlx_xpm_file_to_image(hub->win->mlx, &str[i],
			&(hub->env->text.east.width), &(hub->env->text.east.height));
	// Do not forget to protect
	hub->env->text.east.data = (int *)mlx_get_data_addr(hub->env->text.east.img,
			&i, &i, &i);
	return (hub->env->text.east.img ? 1 : -1);
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
	while (ft_isprint(str[k]) && str[k] != ' ')
		k++;
	if (str[k])
		str[k++] = '\0';
	ft_pass_spaces(str, &k);
	if (str[k])
		return (-1);
	hub->env->text.west.img = mlx_xpm_file_to_image(hub->win->mlx, &str[i],
			&(hub->env->text.west.width), &(hub->env->text.west.height));
	// Do not forget to protect
	hub->env->text.west.data = (int *)mlx_get_data_addr(hub->env->text.west.img,
			&i, &i, &i);
	return (hub->env->text.west.img ? 1 : -1);
}
