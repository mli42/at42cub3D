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

# define WIN_X 200
# define WIN_Y 200
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define EXIT_CODE 53

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

# define BLUE 0x7fffff
# define GREEN 0xff00
# define D_BLUE 0x555
# define D_RED 0x7f0000
# define RED 0xff0000
# define GREY 0x333333

// M_PI/18
# define RAD_10 0.1745329251994
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
	double	pos_rad;
	double	dir_rad;
	double	pov_min_rad;
	double	pov_max_rad;
}				t_vectors;

typedef struct	s_param
{
	t_win		*draw;
	t_vectors	*space;
}				t_param;

int				ft_error(char *str, t_param *hub);
void			*ft_memalloc(int size);

# include <stdio.h>

void			ft_draw(t_param *hub);

// TMP functions

void			ft_winsize(int tab[2]);
char			*ft_map(int fd);
void			ft_draw_square(t_win *draw);
int				fct(int keycode, void *param);

// Other

t_vectors		*ft_init_space(void);
void			ft_recalculate_povs(t_vectors *space);
double			ft_abs_double(double nbr);
int				ft_remove_all(t_param *hub);

#endif
