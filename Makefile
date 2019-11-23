# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shendric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 22:24:02 by shendric          #+#    #+#              #
#    Updated: 2019/10/03 22:24:08 by shendric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

SRC = main.c functions.c menu.c controls.c draw.c menu_draw.c extra.c
OBJ = $(SRC:.c=.o)
MLX = -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit

SRCDIR = sources
OBJDIR = objects
LIBDIR = libs/libft
MLXDIR = libs/mlx

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = $(LIBDIR)/libft.a $(MLX)
HEADER = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)


GREEN = \x1b[32;1m
RED = \x1b[31;1m
RESET = \x1b[0m

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I includes -I $(LIBDIR)/includes -I $(MLXDIR) $< -o $@

$(NAME): $(OBJS)
	@make -s -C $(MLXDIR)
	@make -s -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)[$(NAME) executable created]$(RESET)"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean
	@echo "$(RED)[$(OBJDIR) was removed]$(RESET)"
	@echo "$(RED)[object files were removed]$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a
	@rm -f $(MLXDIR)/libmlx.a
	@echo "$(RED)[$(NAME) executable was removed]$(RESET)"
	@echo "$(RED)[$(LIBDIR)/libft.a was removed]$(RESET)"
	@echo "$(RED)[$(MLXDIR)/libmlx.a was removed]$(RESET)"

re: fclean all
