/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:44:46 by mli               #+#    #+#             */
/*   Updated: 2020/01/05 13:24:22 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		f_ref_s(t_param *hub, char *str)
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

	printf("Sprite opening : '%s'\n", &str[i]);

	return (str[k] ? -1 : (hub->parse->txt_w->sprit = open(&str[i], O_RDONLY)));
}

int		f_ref_so(t_param *hub, char *str)
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

	printf("South opening : '%s'\n", &str[i]);

	return (str[k] ? -1 : (hub->parse->txt_w->south = open(&str[i], O_RDONLY)));
}

int		f_ref_no(t_param *hub, char *str)
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

	printf("North opening : '%s'\n", &str[i]);

	return (str[k] ? -1 : (hub->parse->txt_w->north = open(&str[i], O_RDONLY)));
}

int		f_ref_ea(t_param *hub, char *str)
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

	printf("East opening : '%s'\n", &str[i]);

	return (str[k] ? -1 : (hub->parse->txt_w->east = open(&str[i], O_RDONLY)));
}

int		f_ref_we(t_param *hub, char *str)
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

	printf("West opening : '%s'\n", &str[i]);

	return (str[k] ? -1 : (hub->parse->txt_w->west = open(&str[i], O_RDONLY)));
}
