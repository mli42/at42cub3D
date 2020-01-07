/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:16:52 by mli               #+#    #+#             */
/*   Updated: 2020/01/06 14:06:44 by mli              ###   ########.fr       */
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
# define WIN_X_MAX 2560
# define WIN_Y_MAX 1600
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
# define CHECK_STEP 0.005
# define FOOT_STEP 0.05

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
	int		win_size[2]; // Dont forget to set a limit !!
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

typedef struct	s_fd
{
	int north;
	int south;
	int west;
	int east;
	int sprit;
}				t_fd;

typedef struct	s_parsing
{
	int		**map;
	int		map_len;
	int		map_size;
	t_fd	*txt_w;
	int		ceiling_color;
	int		floor_color;
}				t_parsing;

typedef struct	s_param
{
	t_win		*draw;
	t_vectors	*space;
	t_funct		*funct;
	t_parsing	*parse;
}				t_param;

int				ft_error(char *str, t_param *hub);

# include <stdio.h>

void			ft_draw(t_param *hub);

// TMP functions

void			ft_draw_square(t_win *draw);
int				fct(int keycode, void *param);

// Other

t_param			*ft_hub_alloc(void);
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

int				get_next_line(int fd, char **line);

/* Parsing */
typedef struct	s_ref
{
	char	*ref[7];
	int		(*f_ref[7])();
}				t_ref;

int				ft_parse(t_param *hub, char *filename);
int				ft_good_name(char *filename);
t_ref			ft_ref_parse(void);
int				f_ref_resolution(t_param *hub, char *str);
int				f_ref_floor(t_param *hub, char *str);
int				f_ref_ceiling(t_param *hub, char *str);
void			ft_pass_spaces(char *str, int *i);
int				f_ref_s(t_param *hub, char *str);
int				f_ref_so(t_param *hub, char *str);
int				f_ref_no(t_param *hub, char *str);
int				f_ref_we(t_param *hub, char *str);
int				f_ref_ea(t_param *hub, char *str);
int				ft_allve_been_called(t_param *hub);
int				ft_map_parse(t_param *hub, char *line, int fd, int i);

# define PASSED_ERROR -2

int		ft_isposition(char c);
int		ft_ismapchar(char c);
int		ft_translate(t_param *hub, t_list **alst);

/* Parsing */

#endif
