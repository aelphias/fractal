# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 18:12:10 by aelphias          #+#    #+#              #
#    Updated: 2020/08/14 20:47:24 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME 		= 	fractol

HEADER 		= 	fractol.h

FLAGS		=	-Wextra -Wall -Werror -g -O3

FRAMEWORKS	=	-lmlx -framework OpenGL -framework AppKit

SRC			= 	*.c

all: 
	gcc $(FLAGS) $(FRAMEWORKS) -I$(HEADER) $(SRC) -o $(NAME) 

norm:	
	norminette *.c *.h
		
clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	
re: fclean all