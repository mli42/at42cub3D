/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_printbits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 23:23:42 by mli               #+#    #+#             */
/*   Updated: 2020/03/17 15:38:54 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_printbits(t_ftpf *ftpf, long long int nbr, int size)
{
	int		k;
	int		octect;
	char	*str;

	if (size == -1)
		size = 4;
	str = (char *)&nbr;
	ftpf->res += size * 8;
	while (--size > -1)
	{
		k = 8;
		octect = str[size];
		while (--k > -1)
			ft_putchar_fd(((octect >> k) & 1) + 48, ftpf->fd);
		if (size)
			ftpf_write_n_char(ftpf, ' ', 1);
	}
	return (1);
}
