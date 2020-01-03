/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/01/03 16:18:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_good_name(char *filename)
{
	int i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (ft_strcmp(&filename[i], ".cub"))
		return (-1);
	return (open(filename, O_RDONLY));
}
