# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 19:30:43 by mli               #+#    #+#              #
#    Updated: 2020/05/01 22:09:17 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX_PATH = ./minilibx_opengl_20191021/
MLX_NAME = libmlx.a

LIBFT_PATH = ./libft/
LIBFT = libft.a

LIBS = ${addprefix ${MLX_PATH}, ${MLX_NAME}} ${addprefix ${LIBFT_PATH}, ${LIBFT}}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

PARSING_PATH = ./parsing/
PARSING_FILES = parsing.c filename.c ref.c utils.c textures.c allve_been_called.c \
				ft_map_parse.c translated.c correct_map.c ft_is_close.c
PARSING_SRCS = ${addprefix ${PARSING_PATH}, ${PARSING_FILES}}

SPRITES_PATH = ./disp_sprites/
SPRITES_FILES = ft_draw_sprites.c ft_affine.c faffine_finder.c
SPRITES_SRCS = ${addprefix ${SPRITES_PATH}, ${SPRITES_FILES}}

SRCS_FILES = main.c error.c utils.c ft_remove_all.c raycasting.c calculus.c \
			 fct_moves_ptr.c fct_moves_wasd.c key_switch.c options.c put_textures.c \
			 ft_save.c options2.c options3.c \
			 ${PARSING_SRCS} ${SPRITES_SRCS}

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS_FILES:.c=.o}}
OBJS_PATHS = ${OBJS_PATH} ${addprefix ${OBJS_PATH}, ${PARSING_PATH}} \
			 ${addprefix ${OBJS_PATH}, ${SPRITES_PATH}}

all:
	@make -C ${MLX_PATH}
	@make -C ${LIBFT_PATH}
	@printf "\033[1mMake cub3D\033[0m : "
	@make ${NAME}

$(NAME): ${LIBS} ${OBJS_PATHS} ${OBJS}
	@echo ""
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit -L ${LIBFT_PATH} -lft

${OBJS_PATHS}:
	@mkdir -p $@

${OBJS_PATH}%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "\033[0;33m▓\033[0;0m"

$(MLX_PATH)$(MLX_NAME):
	@echo "\033[1mMake mlx\033[0;0m"
	@make -C ${MLX_PATH}

$(LIBFT_PATH)$(LIBFT):
	@echo "\033[1mMake libft\033[0;0m"
	@make -C ${LIBFT_PATH}

clean:
	@echo "\033[1m\x1b[33mRemove......... |\x1b[32m| done\x1b[0m"
	@rm -rf ${OBJS} ${OBJS_PATH}

fclean: clean
	@echo "\033[1m\x1b[33mRemove all..... |\x1b[32m| done\x1b[0m"
	@rm -rf $(NAME)
	@make -C ${MLX_PATH} clean
	@make -C ${LIBFT_PATH} fclean

re: fclean all

work: all clean

.PHONY: all clean fclean re work
