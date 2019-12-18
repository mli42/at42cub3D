/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:00:25 by mli               #+#    #+#             */
/*   Updated: 2019/12/10 12:06:28 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_windraw(t_win *draw)
{
	free(draw);
	draw = NULL;
}

int		ft_error(char *str, t_win *draw)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	ft_free_windraw(draw);
	return (-1);
}

t_vectors	*ft_init(void)
{
	t_vectors	*result;

	if (!(result = (t_vectors *)ft_memalloc((int)sizeof(t_vectors))))
		return (NULL);
	// Being at the center
	result->pos.x = 3;
	result->pos.y = 3;
	// Watching North
	result->dir.x = 0;
	result->dir.y = 1;

	return (result);
}
