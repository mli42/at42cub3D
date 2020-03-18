/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:43:26 by mli               #+#    #+#             */
/*   Updated: 2020/03/17 18:37:01 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 50

typedef struct	s_gnl
{
	int				min;
	int				max;
	char			*tab;
	struct s_gnl	*next;
}				t_gnl;

typedef struct	s_struct
{
	int				fd;
	t_gnl			*list;
	struct s_struct	*next;
}				t_struct;

int				get_next_line(int fd, char **line);
int				ft_gnl(int fd, char **line, t_gnl **alst);
t_struct		*ft_addfront_fd(t_struct **astruct, int fd);
t_gnl			*ft_lstnew_gnl(int fd);
void			ft_lstclear_gnl(t_gnl **alst);

#endif
