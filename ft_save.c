/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:47:45 by mli               #+#    #+#             */
/*   Updated: 2020/02/25 18:03:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	wr_bitmap_file_header(t_hub *hub, int fd, unsigned int wr)
{
	int ret;

	ret = 0;
	ret |= write(fd, &wr, 2);
	wr = hub->win->win_size[0] * hub->win->win_size[1] * 4 + 14 + 40;
	ret |= write(fd, &wr, 4);
	wr = 0;
	ret |= write(fd, &wr, 4);
	wr = 14 + 40;
	ret |= write(fd, &wr, 4);
	return (ret);
}

static int	wr_bitmap_info_header(t_hub *hub, int fd, unsigned int wr)
{
	int ret;

	ret = 0;
	ret |= write(fd, &wr, 4);
	wr = hub->win->win_size[0];
	ret |= write(fd, &wr, 4);
	wr = (unsigned int)-hub->win->win_size[1];
	ret |= write(fd, &wr, 4);
	wr = 1;
	ret |= write(fd, &wr, 2);
	wr = 32;
	ret |= write(fd, &wr, 2);
	wr = 0;
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	ret |= write(fd, &wr, 4);
	return (ret);
}

static int	write_bmp_header(t_hub *hub, int fd)
{
	int ret;

	ret = 0;
	ret |= wr_bitmap_file_header(hub, fd, 0x4d42);
	ret |= wr_bitmap_info_header(hub, fd, 40);
	return (ret);
}

void		ft_save(t_hub *hub)
{
	int fd;
	int	ret;

	ret = 0;
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT | O_TRUNC,
					S_IRWXU | S_IRGRP | S_IROTH)) < 0)
		exit(ft_error("Can't create a .bmp file", hub));
	if (((write_bmp_header(hub, fd)) < 1) ||
	((write(fd, hub->win->img_data,
		hub->win->win_size[0] * hub->win->win_size[1] * 4)) < 1))
		ret = -1;
	close(fd);
	if (ret == -1)
		exit(ft_error("Can't write in .bmp file", hub));
}
