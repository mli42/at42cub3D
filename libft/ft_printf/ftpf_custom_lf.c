/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_custom_lf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:42:04 by mli               #+#    #+#             */
/*   Updated: 2020/03/17 16:53:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	ft_decimal_part(double nb)
{
	return (nb - (int)nb);
}

void	ftpf_wr_decimal(t_ftpf *ftpf, double d, int precision)
{
	if (precision > 0)
	{
		ft_putchar_fd((int)(d * 10) + 48, ftpf->fd);
		(ftpf->res)++;
		ftpf_wr_decimal(ftpf, ft_decimal_part(d * 10), --precision);
	}
}

int		ftpf_pzero_lf(t_ftpf *ftpf, t_printf *args, int i, float d)
{
	const int len = ft_nbrlen(i);

	if (d >= 0.5)
		i++;
	if (args->flags == '-')
		ft_putnbr_fd(i, ftpf->fd);
	if (args->flags == '0' && i < 0)
		ftpf_write_n_char(ftpf, '-', 1);
	ftpf_write_n_char(ftpf, args->flags != '0' ? ' ' : '0', args->width - len);
	if (args->flags != '-')
	{
		if (i < 0 && args->flags != '0')
			ftpf_write_n_char(ftpf, '-', 1);
		ft_putnbr_fd((i < 0 ? -i : i), ftpf->fd);
	}
	ftpf->res += len;
	return (1);
}

void	ftpf_write_float(t_ftpf *ftpf, t_printf *args, double d)
{
	ft_putnbr_fd((long int)d, ftpf->fd);
	ftpf->res += ft_nbrlen((long int)d);
	ftpf_write_n_char(ftpf, '.', 1);
	ftpf_wr_decimal(ftpf, ft_decimal_part((d < 0 ? -d : d)), args->precision);
}

int		ftpf_custom_lf(t_ftpf *ftpf, t_printf *args, double d)
{
	int len;
	int max;

	if (args->precision == -1)
		args->precision = 6;
	else if (args->precision == 0)
		return (ftpf_pzero_lf(ftpf, args, (int)d, ft_decimal_part(d)));
	len = ft_nbrlen((long int)(d >= 0 ? d : -d)) + 1 + args->precision;
	max = (args->width > len ? args->width : len) - (d < 0 ? 1 : 0);
	if (args->flags == '-')
		ftpf_write_float(ftpf, args, d);
	if (args->flags == '0' && d < 0)
		ftpf_write_n_char(ftpf, '-', 1);
	ftpf_write_n_char(ftpf, args->flags != '0' ? ' ' : '0', max - len);
	if (args->flags != '-')
	{
		if (d < 0 && args->flags != '0')
			ftpf_write_n_char(ftpf, '-', 1);
		ftpf_write_float(ftpf, args, (d >= 0 ? d : -d));
	}
	return (1);
}
