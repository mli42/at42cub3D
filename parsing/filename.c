/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 22:52:57 by mli               #+#    #+#             */
/*   Updated: 2020/01/04 22:39:13 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_good_name(char *filename)
{
	char	*str;

	if ((str = ft_strrchr(filename, '.')) == NULL || ft_strcmp(str, ".cub"))
		return (-1);
	return (open(filename, O_RDONLY));
}
