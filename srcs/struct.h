/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:16:52 by mli               #+#    #+#             */
/*   Updated: 2020/03/06 13:57:54 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum			e_options
{
	e_minimap,
	e_shadow,
	e_sprite,
	e_nb_options
};

enum			e_game_state
{
	e_sp_nothing,
	e_sp_eatable,
	e_sp_collision,
	e_sp_limit
};

enum			e_varname
{
	bit_per_pixel,
	sizeLine,
	endian,
	end
};

typedef struct	s_icoord
{
	int x;
	int y;
}				t_icoord;

typedef struct	s_coord
{
	double x;
	double y;
}				t_coord;

typedef struct	s_sp
{
	int		size;
	double	distance;
	double	offset;
	double	ray;
	t_coord	center;
}				t_sp;

typedef struct	s_walls
{
	int		face;
	int		size;
	double	distance;
	t_coord	check_pt;
}				t_walls;

typedef struct	s_data
{
	void	*img;
	int		*data;
	int		width;
	int		height;
}				t_data;

typedef struct	s_text
{
	t_data north;
	t_data south;
	t_data west;
	t_data east;
	t_data sprite;
}				t_text;

typedef struct	s_limit
{
	int		len;
	int		border[2];
}				t_limit;

typedef struct	s_env
{
	int		**map;
	t_limit	*width;
	int		full_width;
	int		full_height;
	int		ceiling_color;
	int		floor_color;
	t_text	text;
}				t_env;

typedef struct	s_funct
{
	int		*ref;
	char	*switch_;
	void	(**fct)();
}				t_funct;

typedef struct	s_fct_r
{
	const char	*ref;
	int			(**fct)();
}				t_fct_r;

typedef struct	s_entity
{
	t_coord	pos;
	t_coord	dir;
	double	dir_rad;
	float	speed;
	float	life;
}				t_entity;

typedef struct	s_player
{
	t_entity	entity;
	t_coord		pov_min;
	t_coord		pov_max;
	double		pov_min_rad;
	double		pov_max_rad;
	char		collision;
}				t_player;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	int		win_size[2];
}				t_win;

typedef struct	s_hub
{
	t_win		*win;
	t_player	*player;
	t_funct		*fct_moves;
	t_env		*env;
	char		options[e_nb_options];
}				t_hub;

typedef struct	s_faffine
{
	double	a;
	double	b;
}				t_faffine;

#endif
