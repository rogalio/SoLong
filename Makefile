# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 18:03:08 by codespace         #+#    #+#              #
#    Updated: 2023/07/31 18:56:19 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
LFLAGS = -L./mlx_mac -lmlx -framework OpenGL -framework AppKit
MLX = ./mlx_mac/libmlx.a
SRCS = main.c handlers/error_handler.c handlers/event_handlers.c utils/map_utils.c utils/texture_utils.c utils/utils.c utils/game_utils.c
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