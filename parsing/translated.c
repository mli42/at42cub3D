/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:28:49 by mli               #+#    #+#             */
/*   Updated: 2020/01/07 18:20:48 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map(t_param *hub)
{
	int i = -1;
	int j = -1;
	int **map = hub->parse->map;

	while (++i < hub->parse->map_size)
	{
		j = -1;
		while (++j < hub->parse->map_len)
		{
			if (ft_isdigit(map[i][j] + 48))
				printf(" %d ", map[i][j]);
			else
				printf(" %c ", map[i][j]);
		}
		printf("\n");
	}
}

int		ft_translate(t_param *hub, t_list **alst)
{
	int		i;
	t_list	*lst;

	if ((hub->parse->map_size = ft_lstsize(*alst) - 1) < 3)
		return (-1);
	if (!(hub->parse->map = ft_memalloc(sizeof(int *) * hub->parse->map_size)))
		return (0);
	i = -1;
	while (++i < hub->parse->map_size)
	{
		lst = (*alst)->next;
		ft_free((void **)alst);
		*alst = lst;
		(hub->parse->map)[i] = (*alst)->content;
	}
	ft_free((void **)alst);
	print_map(hub);
	return (1);
}
