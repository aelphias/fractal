# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 18:12:10 by aelphias          #+#    #+#              #
#    Updated: 2020/08/14 23:11:04 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME = fractol
SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC_INC_DIR = ./includes
INC_C = ./includes/fractol.h
SRC_FILES =  calculate.c ft_bzero.c key.c main.c black.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
INCL = -I$(SRC_INC_DIR)
FRAME = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wextra -Wall $(INCL)
LFLGS = -lmlx -lm $(FRAME)
.PHONY: clean fclean all re
all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJS)
	@gcc -o $(NAME) -O3 $(FLAGS) $(OBJS) $(LFLGS)
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_C)
	@gcc $(FLAGS) -c -O3 $< -o $@
clean:
	@rm -rf $(OBJ_DIR)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
