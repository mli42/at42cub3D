/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:10:00 by mli               #+#    #+#             */
/*   Updated: 2020/03/17 19:19:42 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include "libft.h"
# include "ftpf_struct.h"

int			ft_printf(const char *str, ...);

int			ftpf_is_handled(const char *handled, const char c, int *i);
int			ftpf_va_atoi(const char *str, int *i, va_list ap, t_printf *args);
char		ftpf_flags(const char *str, int *i);
int			ftpf_precision(const char *str, int *i, va_list ap, t_printf *args);

long int	power_of_2(int y);

int			ftpf_is_c(t_ftpf *ftpf, t_printf *args, int c);
int			ftpf_is_s(t_ftpf *ftpf, t_printf *args, char *str);
int			ftpf_is_p(t_ftpf *ftpf, t_printf *args, void *str);
int			ftpf_is_diux(t_ftpf *ftpf, t_printf *args, long int d);
int			ftpf_is_ux(t_ftpf *ftpf, t_printf *args, unsigned long int u);

int			ftpf_write(t_ftpf *ftpf, const void *str, int nb);
int			ftpf_write_n_char(t_ftpf *ftpf, const int c, int nb);

int			ftpf_get_special(const char *str, int *i, t_ftpf *ftpf, va_list ap);

int			ftpf_custom_lf(t_ftpf *ftpf, t_printf *args, double d);
int			ftpf_printbits(t_ftpf *ftpf, long long int nbr, int size);

double		ft_decimal_part(double nb);

#endif
