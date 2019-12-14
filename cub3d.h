/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:16:52 by mli               #+#    #+#             */
/*   Updated: 2019/12/13 13:46:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./minilibx_opengl_20191021/X.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include "./libft/libft.h"

# define WIN_X 1000
# define WIN_Y 1000
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define BLUE 0x7fffff
# define GREEN 0xff00
# define D_BLUE 0x555
# define D_RED 0x7f0000
# define RED 0xff0000
# define GREY 0x333333

enum			e_varname
{
	bit_per_pixel,
	sizeLine,
	endian,
	end
};

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	int		win_size[2];
}				t_win;

typedef struct	s_coord
{
	double x;
	double y;
}				t_coord;

typedef struct	s_vectors
{
	t_coord pos;
	t_coord dir;
	t_coord pov;
	t_coord pov_min;
	t_coord pov_max;
}				t_vectors;

int				ft_error(char *str);
void			*ft_memalloc(int size);

# include <stdio.h>

#endif
