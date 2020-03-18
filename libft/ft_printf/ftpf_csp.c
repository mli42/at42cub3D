/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:45:09 by mli               #+#    #+#             */
/*   Updated: 2020/03/14 18:32:55 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ftpf_is_c(t_ftpf *ftpf, t_printf *args, int c)
{
	char	flags;

	flags = (args->flags == '0' ? '0' : ' ');
	c %= power_of_2((int)sizeof(unsigned char) * 8);
	if (args->flags == '-')
		ftpf_write(ftpf, &c, 1);
	ftpf_write_n_char(ftpf, flags, args->width - 1);
	if (args->flags != '-')
		ftpf_write(ftpf, &c, 1);
	return (1);
}

int			ftpf_is_s(t_ftpf *ftpf, t_printf *args, char *str)
{
	int		len;
	int		max;
	char	flags;

	len = 0;
	flags = (args->flags == '0' ? '0' : ' ');
	if (!str)
		str = "(null)";
	while ((args->precision < 0 || args->precision > len) && str[len])
		len++;
	max = (args->width > len ? args->width : len);
	if (args->flags == '-')
		ftpf_write(ftpf, str, len);
	ftpf_write_n_char(ftpf, flags, max - len);
	if (args->flags != '-')
		ftpf_write(ftpf, str, len);
	return (1);
}

int			ftpf_is_p(t_ftpf *ftpf, t_printf *args, void *str)
{
	int		len;
	int		max;
	char	*res;

	if (!(res = ft_itoa_lbase("0123456789abcdef", (unsigned long int)str)))
		return (-1);
	len = ft_strlen(res) + 2;
	max = (args->width > len ? args->width : len);
	if (args->flags == '-')
	{
		ftpf_write(ftpf, "0x", 2);
		ftpf_write(ftpf, res, len - 2);
	}
	ftpf_write_n_char(ftpf, ' ', max - len);
	if (args->flags != '-')
	{
		ftpf_write(ftpf, "0x", 2);
		ftpf_write(ftpf, res, len - 2);
	}
	free(res);
	return (1);
}
