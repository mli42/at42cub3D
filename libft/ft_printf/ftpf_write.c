/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:32:37 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 15:14:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_write(t_ftpf *ftpf, const void *str, int nb)
{
	ftpf->res += write(ftpf->fd, str, nb);
	return (1);
}

int		ftpf_write_n_char(t_ftpf *ftpf, const int c, int nb)
{
	while (nb-- > 0)
		ftpf->res += write(ftpf->fd, &c, 1);
	return (1);
}
