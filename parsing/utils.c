/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:48:49 by mli               #+#    #+#             */
/*   Updated: 2020/01/05 18:36:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pass_spaces(char *str, int *i)
{
	if (str)
		while (str[*i] == ' ')
			(*i)++;
}

int		ft_isposition(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		ft_ismapchar(char c)
{
	if (ft_isposition(c) || ft_isdigit(c))
		return (1);
	return (0);
}
