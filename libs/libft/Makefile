# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shendric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:54:33 by shendric          #+#    #+#              #
#    Updated: 2019/09/25 11:51:08 by shendric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isalnum.c ft_bzero.c ft_isascii.c ft_isalpha.c \
		  ft_isprint.c ft_isdigit.c ft_memalloc.c ft_memchr.c ft_itoa.c \
		  ft_memcmp.c ft_memdel.c ft_memcpy.c ft_memccpy.c ft_putchar.c \
		  ft_memset.c ft_memmove.c ft_putchar_fd.c ft_putendl_fd.c \
		  ft_putendl.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		  ft_strchr.c ft_strclr.c ft_strcat.c ft_strdel.c ft_strcmp.c \
		  ft_strcpy.c ft_strdup.c ft_striter.c ft_striteri.c ft_strlen.c \
		  ft_strequ.c ft_strjoin.c ft_strlcat.c ft_strmapi.c ft_strmap.c \
		  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnequ.c \
		  ft_strrchr.c ft_strnstr.c ft_strsub.c ft_tolower.c ft_strstr.c \
		  ft_toupper.c ft_strtrim.c ft_strsplit.c ft_int_length.c \
		  ft_lstiter.c ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		  ft_lstmap.c get_next_line.c
SRCDIR = sources

CC = gcc

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
HEADER = -I includes

FLAGS = -Wall -Wextra -Werror

GREEN = \x1b[32;1m
RED = \x1b[31;1m
RESET = \x1b[0m

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRCS) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)[$(NAME) library created]$(RESET)"


clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)[$(NAME) library removed]$(RESET)"

re: fclean all

.PHONY: clean all re fclean
