/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:09:39 by mli               #+#    #+#             */
/*   Updated: 2020/03/17 15:40:39 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_type(t_ftpf *ftpf, va_list ap, t_printf *args)
{
	int		result;

	result = 0;
	if (args->type == 'c')
		result = ftpf_is_c(ftpf, args, va_arg(ap, int));
	else if (args->type == 's')
		result = ftpf_is_s(ftpf, args, va_arg(ap, char *));
	else if ((args->type == 'x') || (args->type == 'X') || (args->type == 'u'))
		result = ftpf_is_ux(ftpf, args, va_arg(ap, unsigned int));
	else if (args->type == 'p')
		result = ftpf_is_p(ftpf, args, va_arg(ap, void *));
	else if ((args->type == 'd') || (args->type == 'i'))
		result = ftpf_is_diux(ftpf, args, (int)va_arg(ap, int));
	else if (args->type == '%')
		result = ftpf_is_c(ftpf, args, '%');
	else if (args->type == 'f')
		result = ftpf_custom_lf(ftpf, args, va_arg(ap, double));
	else if (args->type == 'b')
		result = ftpf_printbits(ftpf, va_arg(ap, long long int), args->width);
	return (result);
}

int		ftpf_found_conv(const char *str, int *i, t_ftpf *ftpf, va_list ap)
{
	t_printf	args;
	const char	*handled = "cspdiuxXfb%";

	(*i)++;
	args.flags = ftpf_flags(str, i);
	args.width = ftpf_va_atoi(str, i, ap, &args);
	args.precision = ftpf_precision(str, i, ap, &args);
	if ((args.type = ftpf_is_handled(handled, str[*i], i))  == -1 ||
		ftpf_type(ftpf, ap, &args) == -1)
		return (0);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	ap;
	t_ftpf	ftpf;

	i = 0;
	ftpf.fd = 1;
	ftpf.res = 0;
	va_start(ap, str);
	while (str[i] && ftpf.res >= 0)
	{
		j = 0;
		while (str[i] && str[i] != '%' && str[i] != '{')
		{
			i++;
			j++;
		}
		if (j)
			ftpf_write(&ftpf, &str[i - j], j);
		if ((str[i] == '%' && !ftpf_found_conv(str, &i, &ftpf, ap)) ||
			(str[i] == '{' && !ftpf_get_special(str, &i, &ftpf, ap)))
			ftpf.res = -1;
	}
	va_end(ap);
	return (ftpf.res);
}
