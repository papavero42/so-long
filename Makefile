# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdi-pint <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:31:26 by pdi-pint          #+#    #+#              #
#    Updated: 2023/12/19 13:31:29 by pdi-pint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
RM = rm -f
LINKS_LINUX = -lX11 -lm -lXext

MINILIBX = mlx/libmlx.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SRC = ft_render.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft_comp mlx_comp comp

libft_comp:
	make -C libft/
mlx_comp:
	make -C mlx/
printf_comp:
	make -c ft_printf/

comp:
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINILIBX) $(LINKS_LINUX) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C mlx/
	make clean -C libft/
	$(RM) $(NAME)

re: fclean all
