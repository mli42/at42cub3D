# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 19:30:43 by mli               #+#    #+#              #
#    Updated: 2019/12/09 18:55:42 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX_PATH = ./minilibx_opengl_20191021/
MLX_NAME = libmlx.a

LIBFT_PATH = ./libft/
LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_FILES = main.c error.c utils.c tmp.c

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

.PHONY: all clean fclean re work
