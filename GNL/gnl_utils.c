/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:53:26 by mli               #+#    #+#             */
/*   Updated: 2020/01/03 01:41:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_lstclear_gnl(t_gnl **alst)
{
	t_gnl	*tmp;

	while ((*alst)->next)
	{
		tmp = (*alst);
		*alst = (*alst)->next;
		free(tmp->tab);
		free(tmp);
	}
}

void	ft_remove_all_gnl(t_gnl **alist)
{
	t_gnl	*tmp;
	t_gnl	*lst;

	lst = *alist;
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

t_gnl	*ft_lstnew_gnl(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
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
