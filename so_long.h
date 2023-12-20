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
}                   t_data;

#endif
