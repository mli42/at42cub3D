# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 19:30:43 by mli               #+#    #+#              #
#    Updated: 2019/12/06 19:48:24 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX_PATH = ./minilibx_opengl_20191021/

MLX_NAME = libmlx.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRCS_FILES = main.c

OBJS = ${SRCS_FILES:.c=.o}

$(NAME): ${OBJS} ${MLX_PATH}${MLX_NAME}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

$(MLX_NAME):
	make -C ${MLX_PATH}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
