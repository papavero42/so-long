NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
RM = rm -f
LINKS_LINUX = -lX11 -lm -lXext

MINILIBX = mlx/libmlx.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GET_NEXT_LINE = get_next_line/get_next_line.a

SRC = ft_render.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft_comp mlx_comp get_next_line_comp comp

libft_comp:
	make -C libft/
mlx_comp:
	make -C mlx/
printf_comp:
	make -C ft_printf/
get_next_line_comp:
	make -C get_next_line/

comp:
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINILIBX) $(GET_NEXT_LINE) $(LINKS_LINUX) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C mlx/
	make clean -C libft/
	make clean -C get_next_line/
	$(RM) $(NAME)

re: fclean all
