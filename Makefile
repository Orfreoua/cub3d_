# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:57:57 by orfreoua          #+#    #+#              #
#    Updated: 2023/03/31 19:43:15 by orfreoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

SRCS			=	srcs/*.c\
					srcs/raycasting/*.c\
					srcs/parsing/*.c\
					srcs/raycasting/ne/*.c\
					srcs/raycasting/nw/*.c\
					srcs/raycasting/se/*.c\
					srcs/raycasting/sw/*.c\
					

DIR_MLX			=	./mlx_linux/

OBJS			= $(SRCS:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -g3 -I ./headers

LIBS			= -L ./mlx_linux/ -lmlx -lXext -lX11 -lm

RM				= rm -f

all:		${NAME}

.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:c=o}

$(NAME):	$(OBJS)
				make -C $(DIR_MLX)
				${CC} $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
				make -C $(DIR_MLX) clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: clean all

.PHONY:		all clean fclean re
