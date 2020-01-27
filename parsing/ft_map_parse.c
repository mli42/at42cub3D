/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:54:36 by mli               #+#    #+#             */
/*   Updated: 2020/01/26 18:28:14 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		*fill_line(char *line, int len)
{
	int i;
	int k;
	int *map_line;

	if (!(map_line = (int *)ft_memalloc(sizeof(int) * len)))
		return (NULL);
	i = -1;
	k = 0;
	while (line[++i])
	{
		ft_pass_spaces(line, &i);
		map_line[k++] = line[i] - (ft_isdigit(line[i]) ? 48 : 0);
	}
	return (map_line);
}

int		ft_map_strlen(char *line)
{
	int i;
	int size;

	i = -1;
	size = 0;
	while (line[++i])
	{
		ft_pass_spaces(line, &i);
		if (ft_ismapchar(line[i]))
			size++;
		else
			return (-1);
	}
	return (size);
}

int		ft_map_parse(t_hub *hub, char *line, int fd, int i)
{
	int		*map_line;
	int		gnl_value;
	t_list	*lst[2];
	t_list	**alst;

	if ((hub->env->map_width = ft_map_strlen(line)) < 3)
		return (-1);
	alst = &lst[0];
	lst[0] = ft_lstnew(NULL);
	gnl_value = (lst[0] ? 1 : -2);
	while (gnl_value == 1 && line[i] == '1')
	{
		if (ft_map_strlen(line) != hub->env->map_width ||
			!(map_line = fill_line(line, hub->env->map_width)))
			gnl_value = -2;
		if (gnl_value == 1 && (lst[1] = ft_lstnew(map_line)))
			ft_lstadd_back(alst, lst[1]);
		ft_free((void **)&line);
		i = 0;
		gnl_value = (gnl_value < 1 || !lst[1] ? -2 : get_next_line(fd, &line));
		ft_pass_spaces(line, &i);
	}
	if (gnl_value < 1)
		return (ft_map_parse_pb(alst, map_line, line, fd));
	return (ft_map_parse_next(hub, alst, line, fd));
}
