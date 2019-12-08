/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:16:52 by mli               #+#    #+#             */
/*   Updated: 2019/12/07 11:17:57 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include "./libft/libft.h"

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

int		ft_error(char *str);
void	*ft_memalloc(int size);

#include <stdio.h>

#endif
