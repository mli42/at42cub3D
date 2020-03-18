/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:48:49 by mli               #+#    #+#             */
/*   Updated: 2020/03/18 14:05:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_spaces_back(char *str, int *i)
{
	if (str)
	{
		(*i)--;
		while (*i > 0 && str[*i] == ' ')
			(*i)--;
		(*i)++;
	}
	return (*i);
}

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

int		ft_ishandledchar(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (1);
	return (0);
}

int		ft_ismapchar(char c)
{
	if (ft_isposition(c) || ft_ishandledchar(c))
		return (1);
	return (0);
}
