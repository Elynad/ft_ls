# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlasne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 10:25:59 by jlasne            #+#    #+#              #
#    Updated: 2017/07/10 18:55:26 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC =	core.c \
		get_total.c \
		init.c \
		linked_lists.c \
		main.c \
		other.c \
		other_2.c \
		parsing.c \
		print.c \
		print_2.c \
		print_3.c \
		sort_reverse.c \
		sort_reverse_time.c \
		sort_time.c \
		sub_ascii_sort.c \
		sub_core.c \
		sub_linked_lists.c \
		sub_nano_sort.c \
		sub_reverse_ascii_sort.c \
		sub_reverse_nano_sort.c \
		sub_reverse_time_sort.c \
		sub_time_sort.c \
		bonus.c \
		other_3.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	libft/libft.a

CC = clang

FLAGS = -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o : $(SRC_PATH)/%.c
		    $(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
		make -C ./libft/

clean:
		rm -rf $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -rf $(NAME)
			make fclean -C ./libft/

re: fclean all

.PHONY : all re clean fclean
