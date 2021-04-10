/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_get_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:04:06 by mli               #+#    #+#             */
/*   Updated: 2020/03/15 13:46:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_end_special(const char *str, int *i)
{
	while (str[*i] && str[*i] != '}')
		(*i)++;
	(*i)++;
}

int		ftpf_get_special(const char *str, int *i, t_ftpf *ftpf, va_list ap)
{
	int			k;
	const char	*refs[] = (const char *[]){"{bold}", "{underline}", "{nobold}",
	"{nounderline}", "{eoc}", "{black}", "{red}", "{green}", "{blue}",
	"{yellow}", "{cyan}", "{magenta}", "{white}", "{inv}"};
	const char	*colors[] = (const char *[]){"\033[1m", "\033[4m", "\033[21m",
	"\033[24m", "\033[0m", "\033[30m", "\033[31m", "\033[32m", "\033[34m",
	"\033[33m", "\033[36m", "\033[35m", "\033[37m", "\033[7m"};

	k = 0;
	while (k < 14 && ft_strncmp(&str[*i], refs[k], ft_strlen(refs[k])))
		k++;
	if (k < 14)
		ft_putstr_fd((char *)colors[k], ftpf->fd);
	else if ((ft_strncmp(&str[*i], "{fd=open}", 9) ||
		((ftpf->fd = open(va_arg(ap, char *), va_arg(ap, int))) < 1)) &&
		(ft_strncmp(&str[*i], "{fd}", 4) || (ftpf->fd = va_arg(ap, int)) < 1))
		return (0);
	ftpf_end_special(str, i);
	return (1);
}
