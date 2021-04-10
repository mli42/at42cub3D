/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:28:49 by mli               #+#    #+#             */
/*   Updated: 2020/03/06 14:00:53 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_translate(t_hub *hub, t_list **alst)
{
	int		i;
	t_list	*lst;

	if (((hub->env->full_height = ft_lstsize(*alst) - 1) < 3) ||
	(!(hub->env->map = ft_memalloc(sizeof(int *) * hub->env->full_height))) ||
	(!(hub->env->width = ft_memalloc(sizeof(t_limit) * hub->env->full_height))))
		return (0);
	i = -1;
	while (++i < hub->env->full_height)
	{
		lst = (*alst)->next;
		ft_free((void **)alst);
		*alst = lst;
		(hub->env->map)[i] = (*alst)->content;
		(hub->env->width)[i].len = (*alst)->len;
		(hub->env->width)[i].border[0] = (*alst)->min;
		(hub->env->width)[i].border[1] = (*alst)->max;
	}
	ft_free((void **)alst);
	return (1);
}

int			ft_map_parse_pb(t_list **alst, int *map_line, char *line, int fd)
{
	if (alst && *alst && map_line)
		if ((ft_lstlast(*alst))->content != map_line)
			ft_free((void **)&map_line);
	ft_free((void **)&line);
	ft_lstclear(alst, free);
	get_next_line(fd, NULL);
	return (-1);
}

static int	ft_longest_w(t_hub *hub)
{
	int i;
	int res;

	i = -1;
	res = -1;
	while (++i < hub->env->full_height)
		if (hub->env->width[i].len > res)
			res = hub->env->width[i].len;
	return (res);
}

int			ft_map_parse_next(t_hub *hub, t_list **alst, char *line, int fd)
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
	if (!(hub->env->full_width = ft_longest_w(hub)) || ft_is_map_good(hub) < 1)
		return (-1);
	return (1);
}
