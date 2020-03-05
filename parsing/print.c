/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:28:42 by mli               #+#    #+#             */
/*   Updated: 2020/03/05 16:28:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_print_list(t_list *begin_list)
{
	int i = -1;

	while (begin_list != NULL)
	{
		if (begin_list->content == NULL)
			printf("%s\n", (char *)begin_list->content);
		else
		{
			i = -1;
			while (++i < begin_list->max)
			{
				if (ft_isdigit(((int *)begin_list->content)[i] + 48))
					printf("%d", ((int *)begin_list->content)[i]);
				else
					printf("%c", ((int *)begin_list->content)[i]);
			}
			printf("\n");
		}
		if (begin_list->next)
			printf(" -> ");
		begin_list = begin_list->next;
	}
	printf("\n");
}

void	print_map(t_hub *hub)
{
	int i = -1;
	int j = -1;
	int **map = hub->env->map;

	while (++i < hub->env->full_height)
	{
		j = -1;
		while (++j < hub->env->width[i].border[1])
		{
			if (ft_isdigit(map[i][j] + 48))
				ft_putnbr(map[i][j]);
			else
				ft_putchar(map[i][j]);
		}
		ft_putchar('\n');
	}
}
