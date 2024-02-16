# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 18:51:51 by mstaali           #+#    #+#              #
#    Updated: 2024/02/15 19:25:53 by mstaali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

M_SOURCES = main.c inits.c render.c events.c \
	utils/colors.c utils/libft.c utils/maths.c

B_SOURCES = bonus/main_bonus.c bonus/render_bonus.c bonus/events_bonus.c \
	utils/colors.c utils/libft.c utils/maths.c inits.c

M_OBJECTS = $(M_SOURCES:.c=.o)

B_OBJECTS = $(B_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) $(M_OBJECTS) $(LDFLAGS) -o $(NAME)

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(B_OBJECTS)
	$(CC) $(CFLAGS) $(B_OBJECTS) $(LDFLAGS) -o $(NAME)

clean : 
	rm -f $(M_OBJECTS) $(B_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean