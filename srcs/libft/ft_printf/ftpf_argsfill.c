/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_argsfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:17:59 by mli               #+#    #+#             */
/*   Updated: 2020/03/14 19:49:58 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_is_handled(const char *handled, const char c, int *i)
{
	if (ft_strchr(handled, c) == NULL)
		return (-1);
	(*i)++;
	return (c);
}

int		ftpf_va_atoi(const char *str, int *i, va_list ap, t_printf *args)
{
	long int result;

	if (str[*i] == '*')
	{
		(*i)++;
		if ((result = va_arg(ap, int)) < 0)
		{
			result *= -1;
			args->flags = '-';
		}
		return ((int)result);
	}
	result = ((str[*i] >= '0' && str[*i] <= '9') ? 0 : -1);
	while (str[*i] >= '0' && str[*i] <= '9')
		result = (10 * result) + str[(*i)++] - '0';
	return (result);
}

char	ftpf_flags(const char *str, int *i)
{
	char	result;

	result = -1;
	while (str[*i] == '0' || str[*i] == '-')
	{
		if (!(str[*i] == '0' && result == '-'))
			result = str[*i];
		(*i)++;
	}
	return (result);
}

int		ftpf_precision(const char *str, int *i, va_list ap, t_printf *args)
{
	int result;

	result = -1;
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
		{
			(*i)++;
			if ((result = va_arg(ap, int)) < 0)
				result = -1;
		}
		else if ((result = ftpf_va_atoi(str, i, ap, args)) == -1)
			result = 0;
	}
	return (result);
}
