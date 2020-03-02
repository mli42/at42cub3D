#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@echo ""
	@ar -rcs $(NOM) $(OBJ)

clean:
	@echo "\033[1m\x1b[33mRemove all MLX. |\x1b[32m| done\x1b[37m"
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 2>/dev/null
	@printf "\033[0;33m▓\033[0;0m"

.m.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.m=.o} 2>/dev/null
	@printf "\033[0;33m▓\033[0;0m"

re: clean all
