/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:52:03 by mli               #+#    #+#             */
/*   Updated: 2020/01/05 20:43:20 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_map_parse_end(t_param *hub, char *line, int gnl_value, int fd)
{
	if (gnl_value <= 0)
	{
		get_next_line(fd, NULL);
		ft_lstclear(&lst, free);
	}
	return (gnl_value == 1 ? 1 : ft_error("Map Reference Error", hub));

	return (1);
}
