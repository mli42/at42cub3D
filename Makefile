# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 19:30:43 by mli               #+#    #+#              #
#    Updated: 2020/01/04 18:46:17 by mli              ###   ########.fr        #
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
GNL_SRCS = ${GNL_PATH}get_next_line.c ${GNL_PATH}gnl_utils.c

PARSING_PATH = ./parsing/
PARSING_FILES = parsing.c filename.c ref.c utils.c textures.c
PARSING_SRCS = ${addprefix ${PARSING_PATH}, ${PARSING_FILES}}

SRCS_FILES = main.c error.c utils.c ft_remove_all.c raycasting.c \
			 funct_ptr.c ft_hub_alloc.c \
			 ${GNL_SRCS} ${PARSING_SRCS}

OBJS = ${SRCS_FILES:.c=.o}

$(NAME): ${OBJS} ${MLX_PATH}${MLX_NAME} ${LIBFT_PATH}${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit -L ${LIBFT_PATH} -lft

$(MLX_PATH)$(MLX_NAME):
	make -C ${MLX_PATH}

$(LIBFT_PATH)$(LIBFT):
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

debug : ${OBJS} ${MLX_PATH}${MLX_NAME} ${LIBFT_PATH}${LIBFT}
	${CC} ${CFLAGS} -g -o ${NAME} ${OBJS} -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit -L ${LIBFT_PATH} -lft


.PHONY: all clean fclean re work
