/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:28:49 by mli               #+#    #+#             */
/*   Updated: 2020/01/05 23:06:26 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			printf("%d", map[i][j]);
			if (j != hub->parse->map_len - 1)
				printf("\n");
		}
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
	while (*alst)
	{
		lst = (*alst)->next;
		ft_free(alst);
		*alst = lst;
		map[i++] = (*alst)->content;
	}
	return (1);
}
