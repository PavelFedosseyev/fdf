# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 13:26:57 by pfedosse          #+#    #+#              #
#    Updated: 2019/09/25 16:29:57 by pfedosse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDES = -I ./includes
MINILIBX = -I ./minilibx_macos -L minilibx_macos -lmlx \
			-framework OpenGL -framework AppKit
LIBFT = libft/libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC =	./src/main.c \
		./src/fillzero.c \
		./src/filllist.c \
		./src/createintarray.c \
		./src/arraystruct.c \
		./src/createiso.c \
		./src/open_window.c \
		./src/letsprint.c \
		./src/printline.c \
		./src/error.c

OBJ = $(SRC:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) $(MINILIBX) -o $(NAME)

clean:
	@/bin/$(RM) $(OBJ)
	@make -C libft clean

fclean: clean
	@/bin/$(RM) $(NAME)
	@make -C libft clean

re: fclean all
