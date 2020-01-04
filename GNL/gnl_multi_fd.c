/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_multi_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:35 by mli               #+#    #+#             */
/*   Updated: 2020/01/04 21:52:30 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (right_fd == NULL)
	{
		if (!ft_addfront_fd(&begin_fd, fd))
			return (-1);
		right_fd = begin_fd;
	}
	if (!line)
	{
		ft_total_remove_fd(&begin_fd, right_fd);
		return (0);
	}
	return_value = ft_gnl(fd, line, &(right_fd->list));
	if (return_value == 0 || return_value == (-1))
		ft_total_remove_fd(&begin_fd, right_fd);
	return (return_value);
}
