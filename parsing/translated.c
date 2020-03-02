/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:28:49 by mli               #+#    #+#             */
/*   Updated: 2020/03/02 11:31:14 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_translate(t_hub *hub, t_list **alst)
{
	int		i;
	t_list	*lst;

	if (((hub->env->map_height = ft_lstsize(*alst) - 1) < 3) ||
	(!(hub->env->map = ft_memalloc(sizeof(int *) * hub->env->map_height))) ||
	(!(hub->env->map_width = ft_memalloc(sizeof(int) * hub->env->map_height))))
		return (0);
	i = -1;
	while (++i < hub->env->map_height)
	{
		lst = (*alst)->next;
		ft_free((void **)alst);
		*alst = lst;
		(hub->env->map)[i] = (*alst)->content;
		(hub->env->map_width)[i] = (*alst)->nb;
	}
	ft_free((void **)alst);
	return (1);
}

int		ft_map_parse_pb(t_list **alst, int *map_line, char *line, int fd)
{
	if (alst && map_line)
		if ((ft_lstlast(*alst))->content != map_line)
			ft_free((void **)&map_line);
	ft_free((void **)&line);
	ft_lstclear(alst, free);
	get_next_line(fd, NULL);
	return (-1);
}

int		ft_map_parse_next(t_hub *hub, t_list **alst, char *line, int fd)
{
	int gnl_value;

	gnl_value = 1;
	while (gnl_value == 1 && !line[0])
	{
		ft_free((void **)&line);
		gnl_value = get_next_line(fd, &line);
	}
	ft_free((void **)&line);
	if (gnl_value != 0)
		return (ft_map_parse_pb(alst, NULL, line, fd));
	get_next_line(fd, NULL);
	if ((ft_translate(hub, alst)) < 1)
	{
		ft_lstclear(alst, free);
		return (-1);
	}
	if (ft_is_map_good(hub) < 1)
		return (-1);
	return (1);
}
