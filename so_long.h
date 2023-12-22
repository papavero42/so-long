#ifndef SO_LONG_H
# define SO_LONG_H


# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define IMG_WIDTH 32
# define IMG_HEIGHT 32
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307


typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_img
{
    void *exit;
    void *wall;
    void *coll;
    void *walkable;
    void *player[4];
    void *grinch;
}                   t_img;

typedef struct s_data
{
    void    *mlx;
    void    *window_ptr;
    t_img	img;
    char    **map;
    int     present;
    t_coord santa_pos;
    t_coord enemy_pos;
    int     moves;
}                   t_data;

#endif
