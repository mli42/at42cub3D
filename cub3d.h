/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:16:52 by mli               #+#    #+#             */
/*   Updated: 2020/01/28 15:59:41 by mli              ###   ########.fr       */
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
# include "./struct.h"

# define WIN_X_MAX 2560
# define WIN_Y_MAX 1440
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

# define RAD_5  0.0872664625997
# define RAD_10 0.1745329251994
# define RAD_30 0.5235987755982
# define POV_60 1.0471975511965
# define RAD_90 1.5707963267948
# define PI2 6.283185307179586
# define CHECK_STEP 0.005
# define FOOT_STEP 0.05

int		ft_error(char *str, t_hub *hub);

# include <stdio.h>

void	ft_draw(t_hub *hub);

// TMP functions

void	ft_draw_square(t_win *draw);
int		fct(int keycode, void *param);

// Other

void	ft_recalculate_povs(t_player *player);
double	ft_abs_double(double nbr);
int		ft_remove_all(t_hub *hub);
void	ft_draw(t_hub *hub);
t_funct	*fct_moves_ptr_init(void);

void	ft_a_key(t_hub *hub);
void	ft_s_key(t_hub *hub);
void	ft_d_key(t_hub *hub);
void	ft_w_key(t_hub *hub);

int		get_next_line(int fd, char **line);

int		ft_parse(t_hub *hub, char *filename);
int		ft_good_name(char *filename);
t_fct_r	*ft_ref_parse(void);
int		f_ref_resolution(t_hub *hub, char *str);
int		f_ref_floor(t_hub *hub, char *str);
int		f_ref_ceiling(t_hub *hub, char *str);
void	ft_pass_spaces(char *str, int *i);
int		f_ref_s(t_hub *hub, char *str);
int		f_ref_so(t_hub *hub, char *str);
int		f_ref_no(t_hub *hub, char *str);
int		f_ref_we(t_hub *hub, char *str);
int		f_ref_ea(t_hub *hub, char *str);
int		ft_allve_been_called(t_hub *hub);
int		ft_map_parse(t_hub *hub, char *line, int fd, int i);

# define PASSED_ERROR -2

int		ft_isposition(char c);
int		ft_ismapchar(char c);
int		ft_translate(t_hub *hub, t_list **alst);
int		ft_map_parse_pb(t_list **alst, int *map_line, char *line, int fd);
int		ft_map_parse_next(t_hub *hub, t_list **alst, char *line, int fd);
int		ft_is_map_good(t_hub *hub);

#endif
