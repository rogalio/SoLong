# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 18:03:08 by codespace         #+#    #+#              #
#    Updated: 2024/01/13 15:12:32 by rogalio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./minilibx  -g
LFLAGS = -L./mlx_mac -lmlx -framework OpenGL -framework AppKit
MLX = ./mlx_mac/libmlx.a
SRCS = main.c handlers/input_handlers.c handlers/event_handlers.c handlers/event_handlers2.c utils/map_utils.c utils/map_utils2.c utils/texture_utils.c utils/utils.c utils/utils2.c utils/utils3.c utils/game_utils.c
OBJS = $(SRCS:.c=.o)

all : $(MLX) $(NAME)

$(MLX) :
	make -sC ./mlx_mac

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	make clean -C ./mlx_mac

re : fclean all

.PHONY: all clean fclean re