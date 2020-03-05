/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:54:36 by mli               #+#    #+#             */
/*   Updated: 2020/03/05 15:55:17 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_lstcpy(t_list **dest, t_list *src)
{
	(*dest)->len = src->len;
	(*dest)->min = src->min;
	(*dest)->max = src->max;
	return (1);
}

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
		map_line[k++] = line[i] - (ft_isdigit(line[i]) ? 48 : 0);
	return (map_line);
}

int		ft_map_strlen(char *line, t_list **lst)
{
	int i;

	i = 0;
	ft_pass_spaces(line, &i);
	(*lst)->min = i;
	while (line[++i])
		if (!(ft_ismapchar(line[i]) || line[i] == ' '))
			return (-1);
	(*lst)->max = ft_spaces_back(line, &i);
	return ((*lst)->max + 1);
}

int		ft_map_parse(t_hub *hub, char *line, int fd, int i)
{
	int		*map_line;
	int		gnl_value;
	t_list	*lst[2];

	lst[0] = ft_lstnew(NULL);
	gnl_value = (lst[0] ? 1 : -2);
	while (gnl_value > -1 && line[i] == '1')
	{
		if ((lst[0]->len = ft_map_strlen(line, &lst[0])) > 0 &&
			(map_line = fill_line(line, lst[0]->len)) &&
			(lst[1] = ft_lstnew(map_line)) && ft_lstcpy(&lst[1], lst[0]))
			ft_lstadd_back(&lst[0], lst[1]);
		else
			gnl_value = -2;
		ft_free((void **)&line);
		i = 0;
		gnl_value = (gnl_value < 0 || !lst[1] ? -2 : get_next_line(fd, &line));
		ft_pass_spaces(line, &i);
	}
	if (gnl_value < 0)
		return (ft_map_parse_pb(&lst[0], map_line, line, fd));
	return (ft_map_parse_next(hub, &lst[0], line, fd));
}
