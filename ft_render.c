#include "so_long.h"
void	ft_render(t_data *window)
{
    window->img.exit= mlx_xpm_file_to_image(window->mlx, "house.xpm", //casetta
			&window->coord.x, &window->coord.y);
    window->img.wall = mlx_xpm_file_to_image(window->mlx, "christmas_tree.xpm", //albero
			&window->coord.x, &window->coord.y);
    window->img.coll = mlx_xpm_file_to_image(window->mlx, //regalo
			"present1.xpm", &window->coord.x, &window->coord.y);
    window->img.walkable= mlx_xpm_file_to_image(window->mlx, //neve
			"snow.xpm", &window->coord.x, &window->coord.y);
	window->img.player[0] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso destra
			"santa_right.xpm", &window->coord.x, &window->coord.y);
	window->img.player[1] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso sinistra
			"santa_left.xpm", &window->coord.x, &window->coord.y);
	window->img.player[2] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso avanti
			"santa_front.xpm", &window->coord.x, &window->coord.y);
	window->img.player[3] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso dietro
			"santa_back.xpm", &window->coord.x, &window->coord.y);
	window->img.grinch = mlx_xpm_file_to_image(window->mlx, //grinch
			"grinch.xpm", &window->coord.x, &window->coord.y);
}
