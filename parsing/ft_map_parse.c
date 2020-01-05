/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:54:36 by mli               #+#    #+#             */
/*   Updated: 2020/01/05 23:06:22 by mli              ###   ########.fr       */
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
			while (++i < 29)
			{
				printf("[%d]", ((int *)begin_list->content)[i]);
//				if (i < 28)
//					printf("| ");
			}
			printf("\n");
		}
		if (begin_list->next)
			printf(" -> ");
		begin_list = begin_list->next;
	}
	printf("\n");
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
	{
		ft_pass_spaces(line, &i);
		if (ft_ismapchar(line[i]))
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

int		ft_correct_line(char *line, int len)
{
	if (ft_map_strlen(line) == len)
		return (1);
	return (0);
}

int		ft_map_parse(t_param *hub, char *line, int fd, int i)
{
	int		*map_line;
	int		gnl_value;
	t_list	*lst[2];
	t_list	**alst;

	if ((hub->parse->map_len = ft_map_strlen(line)) < 3)
		return (-1);
	alst = &lst[0];
	gnl_value = ((lst[0] = ft_lstnew(NULL)) ? 1 : -2);
	while (gnl_value == 1 && line[i] == '1')
	{
		if (!ft_correct_line(line, hub->parse->map_len) ||
			!(map_line = fill_line(line, hub->parse->map_len)))
			gnl_value = -2;
		if (gnl_value == 1)
			if ((lst[1] = ft_lstnew(map_line)))
				ft_lstadd_back(alst, lst[1]);
		ft_free((void **)&line);
		i = 0;
		gnl_value = (gnl_value < 1 || !lst[1] ? -2 : get_next_line(fd, &line));
		ft_pass_spaces(line, &i);
	}
//	gnl_value = (gnl_value > 0 ? ft_suite : -2);
//	line[i] == '\0' ?
	ft_print_list(*alst);
	return (0); // ft_map_parse_end;
}
