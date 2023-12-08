# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 12:40:07 by jolecomt          #+#    #+#              #
#    Updated: 2023/12/08 17:47:25 by jolecomt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	./src/main.c		\
			./src/parsing.c		\
			./src/draw_line.c	\
			./src/color.c		\
			./src/display.c		\
			./src/utils.c	\
			./src/ft_atoi.c 	\
			${SRCS_GNL}		\

SRCS_GNL	=	./src/gnl/get_next_line_utils.c	\
			./src/gnl/get_next_line.c	\

OBJS		=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Ilib/minilibx-linux -g

all:	${OBJS}
	make -C lib/minilibx-linux
	${CC} ${CFLAGS} ${OBJS} lib/minilibx-linux/libmlx.a -lXext -lX11 -lm -o FdF

clean:
	rm ${OBJS}

fclean:	clean
	rm ./FdF

re:
	make fclean
	make

.PHONY: all clean fclean

.SILENT: