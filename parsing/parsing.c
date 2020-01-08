/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/01/08 17:48:42 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_first_vars(t_param *hub, t_ref ref_parse, int fd)
{
	int		i;
	int		k;
	int		gnl_value;
	char	*line;

	i = 0;
	while ((gnl_value = get_next_line(fd, &line)) == 1 && !line[0])
		ft_free((void **)&line);
	ft_pass_spaces(line, &i);
	while (gnl_value == 1 && line[i] != '1')
	{
		k = 0;
		while (k < 7 && ft_strncmp(&line[i], ref_parse.ref[k], 1))
			k++;
		gnl_value = (k < 7 ? ref_parse.f_ref[k](hub, &line[i]) : -1);
		ft_free((void **)&line);
		i = 0;
		if (gnl_value > 0)
			while ((gnl_value = get_next_line(fd, &line)) == 1 && !line[0])
				ft_free((void **)&line);
		ft_pass_spaces(line, &i);
	}
	if ((gnl_value <= 0) || (gnl_value = ft_map_parse(hub, line, fd, i)) <= 0)
		get_next_line(fd, NULL);
	return (gnl_value == 1 ? 1 : ft_error("Map Reference Error", hub));
}

int			ft_parse(t_param *hub, char *filename)
{
	int			fd;

	if ((fd = ft_good_name(filename)) == -1)
		return (ft_error("Given file not correct", hub));
	if (ft_first_vars(hub, ft_ref_parse(), fd) == -1)
		return (-1);
	if (ft_allve_been_called(hub) == -1)
		return (ft_error("Not all references have been called", hub));
	return (1);
}
