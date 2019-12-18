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
# include <math.h>
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

# define RAD_30 0.52359878
# define RAD_90 1.570796

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
	t_coord pov_min;
	t_coord pov_max;
}				t_vectors;

typedef struct	s_param
{
	t_win		*draw;
	t_vectors	*space;
}				t_param;

int				ft_error(char *str, t_win *draw);
void			*ft_memalloc(int size);

# include <stdio.h>

void			ft_draw(t_param param);

// TMP functions

void			ft_winsize(int tab[2]);
char			*ft_map(int fd);
void			ft_draw_square(t_win *draw);
int				fct(int keycode, void *param);

// Other

t_vectors		*ft_init_space(void);
void			ft_recalculate_povs(t_vectors *space);

#endif
