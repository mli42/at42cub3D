/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:53:26 by mli               #+#    #+#             */
/*   Updated: 2020/03/17 23:33:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_struct	*ft_addfront_fd(t_struct **astruct, int fd)
{
	t_struct	*new;

	if (!(new = (t_struct *)malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	if (!(new->list = ft_lstnew_gnl(fd)))
	{
		free(new);
		return (NULL);
	}
	new->next = *astruct;
	*astruct = new;
	return (new);
}

void		ft_total_remove_fd(t_struct **begin_fd, t_struct *to_delete_fd)
{
	t_gnl		*current;
	t_gnl		*then;
	t_struct	*tmp_fd;

	if (!to_delete_fd)
		return ;
	current = to_delete_fd->list;
	while (current)
	{
		then = current->next;
		free(current->tab);
		free(current);
		current = then;
	}
	to_delete_fd->list = NULL;
	if (*begin_fd == to_delete_fd)
		*begin_fd = to_delete_fd->next;
	else
	{
		tmp_fd = *begin_fd;
		while (tmp_fd->next && tmp_fd->next != to_delete_fd)
			tmp_fd = tmp_fd->next;
		tmp_fd->next = tmp_fd->next->next;
	}
	free(to_delete_fd);
}

int			get_next_line(int fd, char **line)
{
	int					return_value;
	static t_struct		*begin_fd = NULL;
	t_struct			*right_fd;

	right_fd = begin_fd;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (right_fd && right_fd->fd != fd)
		right_fd = right_fd->next;
	if (!line)
	{
		ft_total_remove_fd(&begin_fd, right_fd);
		return (-1);
	}
	if (right_fd == NULL)
	{
		if (!ft_addfront_fd(&begin_fd, fd))
			return (-1);
		right_fd = begin_fd;
	}
	return_value = ft_gnl(fd, line, &(right_fd->list));
	if (return_value == 0 || return_value == (-1))
		ft_total_remove_fd(&begin_fd, right_fd);
	return (return_value);
}
