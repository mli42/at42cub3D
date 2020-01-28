# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 19:30:43 by mli               #+#    #+#              #
#    Updated: 2020/01/28 14:16:50 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX_PATH = ./minilibx_opengl_20191021/
MLX_NAME = libmlx.a

LIBFT_PATH = ./libft/
LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

GNL_PATH = ./GNL/
GNL_FILES = get_next_line.c gnl_utils.c gnl_multi_fd.c
GNL_SRCS = ${addprefix ${GNL_PATH}, ${GNL_FILES}}

PARSING_PATH = ./parsing/
PARSING_FILES = parsing.c filename.c ref.c utils.c textures.c allve_been_called.c \
				ft_map_parse.c translated.c correct_map.c
PARSING_SRCS = ${addprefix ${PARSING_PATH}, ${PARSING_FILES}}

SRCS_FILES = main.c error.c utils.c ft_remove_all.c raycasting.c \
			 fct_moves_ptr.c ft_hub_alloc.c \
			 ${GNL_SRCS} ${PARSING_SRCS}

LIBFT_FILES = ft_memset.c ft_bzero.c ft_strlen.c ft_toupper.c ft_tolower.c \
			 ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
			 ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			 ft_isascii.c ft_isprint.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			 ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
			 ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
			 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			 ft_putchar.c ft_putstr.c ft_putnbr.c \
			 ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
			 ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			 ft_strcmp.c ft_memalloc.c ft_free.c ft_atoi_ptr.c

MLX_FILES = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
			mlx_xpm.c mlx_int_str_to_wordtab.c mlx_png.c mlx_mouse.m

VPATH = ${LIBFT_PATH}:${MLX_PATH}


OBJS = ${SRCS_FILES:.c=.o}

$(NAME): ${OBJS} ${MLX_PATH}${MLX_NAME} ${LIBFT_PATH}${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit -L ${LIBFT_PATH} -lft

$(MLX_PATH)$(MLX_NAME): ${MLX_FILES}
	make -C ${MLX_PATH}

$(LIBFT_PATH)$(LIBFT): ${LIBFT_FILES}
	make -C ${LIBFT_PATH}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)
	make -C ${MLX_PATH} clean
	make -C ${LIBFT_PATH} fclean

re: fclean all

work: all clean

.PHONY: all clean fclean re work
