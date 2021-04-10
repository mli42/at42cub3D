/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:23:08 by mli               #+#    #+#             */
/*   Updated: 2020/03/12 12:09:06 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_STRUCT_H
# define FTPF_STRUCT_H

typedef struct	s_printf
{
	char	flags;
	int		width;
	int		precision;
	char	type;
}				t_printf;

typedef struct	s_ftpf
{
	int fd;
	int res;
}				t_ftpf;

#endif
