# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 12:40:55 by frankgar          #+#    #+#              #
#    Updated: 2024/03/16 20:26:49 by frankgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
INCLUDES = -I ./inc/\
		   -I ./libft/
SRC = push_swap.c comprove_utils.c parsing.c rotate.c swap.c push.c utils.c \
		utils2.c main.c print_stack.c

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))


all: dir $(NAME)

-include (DEP)
dir:
	make -C ./libft/
	mkdir -p $(DIR_OBJ)
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) ./libft/libft.a -o $@ $(INCLUDES)
clean:
	rm -rf $(DIR_OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: fclean all clean re dir
