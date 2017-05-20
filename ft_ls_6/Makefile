# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 11:36:50 by mameyer           #+#    #+#              #
#    Updated: 2017/05/20 19:01:53 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =	srcs/main.c \
		srcs/core.c \
		srcs/errors.c \
		srcs/init.c \
		srcs/linked_lists.c \
		srcs/other.c \
		srcs/parsing.c \
		srcs/print_1.c \
		srcs/print_2.c \
		srcs/print_3.c

HDR = libft/libft.a

all : $(NAME)

$(NAME) :
			@ gcc -o $(NAME) $(SRC) $(HDR) \

clean :
			@ rm -f *.o

fclean :	clean
			@ rm -f $(NAME)

re :		fclean all
