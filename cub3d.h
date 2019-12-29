/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:16:52 by mli               #+#    #+#             */
/*   Updated: 2019/12/29 04:16:22 by mli              ###   ########.fr       */
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

# define WIN_X 800
# define WIN_Y 800
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define EXIT_CODE 53

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

# define SKYBLUE 0x7fffff
# define GREEN 0xff00
# define D_BLUE 0x555
# define D_RED 0x7f0000
# define RED 0xff0000
# define GREY 0x333333
# define ORANGE 0xFF6900
# define GREY_FLOOR 0x424242
# define YELLOW 0xFFED2D

// M_PI/18
# define RAD_5  0.0872664625997
# define RAD_10 0.1745329251994
# define RAD_30 0.5235987755982
# define POV_60 1.0471975511965
# define RAD_90 1.5707963267948
# define PI2 M_PI*2
# define CHECK_STEP 0.001
# define FOOT_STEP 0.08

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

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

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

typedef struct	s_funct
{
	int		key_map[8];
	void	(*fct[8])();
}				t_funct;

typedef struct	s_param
{
	t_win		*draw;
	t_vectors	*space;
	t_funct		*funct;
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
void			ft_draw(t_param *hub);
t_funct			*funct_ptr_init(void);

void			ft_arrow_right(t_param *hub);
void			ft_arrow_left(t_param *hub);
void			ft_arrow_up(t_param *hub);
void			ft_arrow_down(t_param *hub);
void			ft_a_key(t_param *hub);
void			ft_s_key(t_param *hub);
void			ft_d_key(t_param *hub);
void			ft_w_key(t_param *hub);
#endif
