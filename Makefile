# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezonda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 11:32:21 by ezonda            #+#    #+#              #
#    Updated: 2019/04/02 15:26:49 by ezonda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = srcs/main.c srcs/parser.c srcs/tools.c srcs/tools_parser.c \
	  srcs/print_ls.c srcs/ascii.c srcs/time.c srcs/long.c srcs/recursive.c \
	  srcs/tools_time.c srcs/tools_time2.c srcs/multi_path.c \
	  srcs/tools_multi_path.c srcs/tools_long.c
#	  recursive.c tools.c tools2.c tools3.c time_order.c tools_time.c \
	  tools_time2.c

OBJ = $(SRC: .c=.o)

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror # -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "Compilation..."
	@$(CC) $(FLAGS) $(LIB) -I./libft $(OBJ) -I./includes -o $(NAME)
	@echo "OK."

$(LIB):
	@make -C libft/ fclean
	@make -C libft/

%.o: %.c
	$(CC) -o $@ -c $< -I./includes

clean:
	@echo "Deleting all object file ..."
	@make -C libft/ clean
	@echo "OK."

fclean:
	@echo "Deleting ./ft_ls"
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "OK."

re: fclean all

.PHONY: clean fclean re all
