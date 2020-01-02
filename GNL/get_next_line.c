/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:32:08 by mli               #+#    #+#             */
/*   Updated: 2020/01/02 16:56:32 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#define BUFFER_SIZE 400

typedef struct	s_list
{
	int				min;
	int				max;
	char			*tab;
	struct s_list	*next;
}				t_list;

void	ft_remove_all(t_list **alist)
{
	t_list	*tmp;
	t_list	*lst = *alist;

	while (lst)
	{
		tmp = lst->next;
		free(lst->tab);
		lst->tab = NULL;
		free(lst);
		lst = tmp;
	}
	*alist = NULL;
}

t_list	*ft_lstnew(int fd)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->min = 0;
	if (!(new->tab = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
	{
		free(new);
		return (NULL);
	}
	if ((new->max = read(fd, new->tab, BUFFER_SIZE)) < 0)
	{
		free(new->tab);
		new->tab = NULL;
		free(new);
		return (NULL);
	}
	new->next = 0;
	return (new);
}

int		ft_sentence(t_list **alist, int min, int max)
{
	int		size = 0;
	char	*tab;
	t_list	*lst = *alist;

	while (lst->next)
	{
		size += lst->max - lst->min;
		lst = lst->next;
	}
	tab = lst->tab;
	if (lst->max == 0)
		return (size);
	while (min < max)
	{
		size++;
		if (tab[min++] == '\n')
			return (size);
	}
	return (0);
}

void    ft_lstclear(t_list **alst)
{
    t_list  *tmp;

    while ((*alst)->next)
    {
        tmp = (*alst);
        *alst = (*alst)->next;
        free(tmp->tab);
        free(tmp);
    }
}

int		ft_found(t_list **alist, char **line, int size)
{
	int i;
	char	*src;
	t_list *lst;

	i = 0;
	lst = *alist;
	src = lst->tab;
	if (!(*line = (char *)malloc(sizeof(char) * size)))
		return (0);
	while (i < size - 1)
	{
		if ((lst->min >= lst->max) && lst->next)
		{
			lst = lst->next;
			src = lst->tab;
		}
		line[0][i++] = src[(lst->min)++];
	}
	if (lst->min >= lst->max && lst->next)
		lst = lst->next;
	line[0][i] = '\0';
	(lst->min)++;
	ft_lstclear(alist);
	return (1);
}

int		ft_size(t_list *lst)
{
	int		size = 1;

	while (lst)
	{
		size = lst->max - lst->min;
		lst = lst->next;
	}
	return (size);
}

int		ft_gnl(int fd, char **line, t_list **alist)
{
	int		size;
	t_list	*list = *alist;

	while (((size = ft_sentence(alist, list->min, list->max)) == 0) &&
			(list->max == BUFFER_SIZE))
	{
		if (!(list->next = ft_lstnew(fd)))
			return (-1);
		list = list->next;
	}
	if (ft_found(alist, line, size) == 0)
		return (-1);
	return ((size > 0 ? 1 : 0));
}

int		get_next_line(int fd, char **line)
{
	static t_list *lst = NULL;
	int		returned_value;

	if (fd < 0 || !line)
		return (-1);
	if (lst == NULL)
		if ((lst = ft_lstnew(fd)) == NULL)
			return (-1);
	returned_value = ft_gnl(fd, line, &lst);
	if (returned_value == 0 || returned_value == -1)
		ft_remove_all(&lst);
	return (returned_value);
}
