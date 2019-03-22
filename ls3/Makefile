# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezonda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 11:32:21 by ezonda            #+#    #+#              #
#    Updated: 2019/03/21 17:55:07 by ezonda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c parser.c tools.c tools_parser.c ls_no_flag.c ascii.c time.c \
	  long.c recursive.c 
#	  recursive.c tools.c tools2.c tools3.c time_order.c tools_time.c \
	  tools_time2.c

OBJ = $(SRC: .c=.o)

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@echo "Compilation..."
	@$(CC) $(LIB) -I./libft $(OBJ) -I./includes -o $(NAME)
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
