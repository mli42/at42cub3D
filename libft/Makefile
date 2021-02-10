# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 17:22:00 by mli               #+#    #+#              #
#    Updated: 2021/02/10 15:21:11 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

INCL_PATH = ./includes/

CFLAGS = -Wall -Wextra -Werror -I ${INCL_PATH}

SRCS_FILES = ft_memset.c ft_bzero.c ft_strlen.c \
			 ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
			 ft_strnstr.c ft_atoi.c \
			 ft_memcpy.c ft_memccpy.c ft_memmove.c \
			 ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
			 ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
			 ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
			 ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			 ft_lstmap.c

OBJS = ${SRCS_FILES:.c=.o}

all:
	@printf "\033[1mMake libft\033[0m : "
	@make ${NAME}

$(NAME): ${OBJS}
	@echo ""
	@ar rcs ${NAME} ${OBJS}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@printf "\033[0;33m▓\033[0m"

clean:
	@echo "\033[1m\x1b[33mRemove libft... |\x1b[32m| done\x1b[0m"
	@rm -rf ${OBJS}

fclean: clean
	@echo "\033[1m\x1b[33mRemove all libft|\x1b[32m| done\x1b[0m"
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
