#
#

NOM=libmlx.a
SRC=mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-w

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ) ||:
	@ranlib $(NOM) ||:
	@echo "\x1b[32;1m[mlx library created]\x1b[0m"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
