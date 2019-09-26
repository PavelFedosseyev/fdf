# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfedosse <pfedosse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 16:28:20 by pfedosse          #+#    #+#              #
#    Updated: 2019/09/25 14:05:04 by pfedosse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRCS =	ft_isdigit.c ft_lstnew.c ft_memset.c ft_putstr_fd.c ft_striteri.c \
		ft_strncpy.c ft_tolower.c ft_isprint.c ft_mallst.c ft_print_list.c ft_strcat.c \
		ft_strjoin.c ft_strnequ.c ft_toupper.c ft_atoi.c ft_itoa.c ft_memccpy.c \
		ft_putchar.c ft_strchr.c ft_strlcat.c ft_strnew.c ft_word.c ft_bzero.c \
		ft_list_size.c ft_memchr.c ft_putchar_fd.c ft_strcmp.c ft_strclr.c ft_strnstr.c \
		ft_count.c ft_lstadd.c ft_memcmp.c ft_putendl.c ft_strcpy.c ft_strlen.c ft_strrchr.c \
		ft_countword.c ft_lstdel.c ft_memcpy.c ft_putendl_fd.c ft_strdel.c ft_strmap.c \
		ft_strsplit.c ft_isalnum.c ft_lstdelone.c ft_memdel.c ft_putnbr.c ft_strdup.c \
		ft_strmapi.c ft_strstr.c ft_isalpha.c ft_lstiter.c ft_memalloc.c ft_putnbr_fd.c \
		ft_strequ.c ft_strncat.c ft_strsub.c ft_isascii.c ft_lstmap.c ft_memmove.c \
		ft_putstr.c ft_striter.c ft_strncmp.c ft_strtrim.c get_next_line.c

OBJECTS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -g -I libft.h -c $(SRCS)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJECTS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all