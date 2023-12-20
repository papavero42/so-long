#include "so_long.h"

static void	ft_select_image(t_data *window, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.walkable, x, y + 30);
	else if (c == '1')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.wall, x, y + 30);
	else if (c == 'C')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.coll, x, y + 30);
	else if (c == 'E')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.exit, x, y + 30);
	else if (c == 'P')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.player[2], x, y + 30);
	else if (c == 'G')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.grinch, x, y + 30);
}
static void	ft_put_image(t_data *window)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (window->map[++j])
	{
		while (window->map[++i])
			ft_select_image(window, window->map[j][i], i * IMG_WIDTH, j * IMG_HEIGHT);
	}
}

void	ft_render(t_data *window)
{
	int	i;

	i = 32;
    window->img.exit= mlx_xpm_file_to_image(window->mlx, "img/house.xpm", //casetta
			&i, &i);
    window->img.wall = mlx_xpm_file_to_image(window->mlx, "img/christmas_tree.xpm", //albero
			&i, &i);
    window->img.coll = mlx_xpm_file_to_image(window->mlx, //regalo
			"img/present1.xpm", &i, &i);
    window->img.walkable= mlx_xpm_file_to_image(window->mlx, //neve
			"img/snow.xpm", &i, &i);
	window->img.player[0] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso destra
			"img/santa_right.xpm", &i, &i);
	window->img.player[1] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso sinistra
			"img/santa_left.xpm", &i, &i);
	window->img.player[2] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso avanti
			"img/santa_front.xpm", &i, &i);
	window->img.player[3] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso dietro
			"img/santa_back.xpm", &i, &i);
	window->img.grinch = mlx_xpm_file_to_image(window->mlx, //grinch
			"img/grinch.xpm", &i, &i);
	ft_put_image(window);
}

static void	ft_map_gen(t_data *window)
{
	int i;
	int	fd;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	window->map[i] = get_next_line(fd);
	while(window->map[i] != NULL)
		window->map[i++] = get_next_line(fd);
}


int	main(void)
{
	t_data	prova;
	prova.present = 5;
	prova.mlx = mlx_init();
	prova.window_ptr = mlx_new_window(prova.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Prova");
	ft_map_gen(&prova);
	ft_render(&prova);
}
