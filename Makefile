# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 18:51:51 by mstaali           #+#    #+#              #
#    Updated: 2024/02/12 20:24:36 by mstaali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

SOURCES = main.c inits.c render.c events.c \
	utils/colors.c utils/libft.c utils/maths.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJECTS) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean