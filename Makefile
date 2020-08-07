# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 19:06:53 by aelphias          #+#    #+#              #
#    Updated: 2020/08/07 21:18:51 by aelphias         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME 		= 	fractol

HEADER 		= 	fractol.h

FLAGS		=	-Wextra -Wall -Werror -g

FRAMEWORKS	=	-lmlx -framework OpenGL -framework AppKit

SRC			= 	*.c


all: 
		gcc $(FRAMEWORKS) -I$(HEADER) $(SRC) -o $(NAME)

norm:	
		norminette *.c *.h
		
clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)
	
re: fclean all