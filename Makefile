# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolecomt <jolecomt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 12:40:07 by jolecomt          #+#    #+#              #
#    Updated: 2023/12/12 17:57:28 by jolecomt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
SRCS		=	./src/main.c		\
			./src/color.c		\
			./src/display.c		\
			./src/ft_atoi.c 	\
			./src/img_utils.c	\
			./src/key_handler.c	\
			./src/line_utils.c	\
			./src/line.c		\
			./src/parsing.c		\
			./src/point_utils.c	\
			./src/utils.c		\
			${SRCS_GNL}		\

SRCS_GNL	=	./src/gnl/get_next_line_utils.c	\
			./src/gnl/get_next_line.c	\

OBJS		=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Ilib/minilibx-linux -g

all:	${NAME}

${NAME} : ${OBJS}
	make -C lib/minilibx-linux
	${CC} ${CFLAGS} ${OBJS} lib/minilibx-linux/libmlx.a -lXext -lX11 -lm -o FdF

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ./FdF

re: fclean all

.PHONY: all clean fclean re

#.SILENT: