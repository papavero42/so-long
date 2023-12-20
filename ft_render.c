#include "so_long.h"

static void	ft_select_image(t_data *window, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.walkable, x, y);
	else if (c == '1')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.coll, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.exit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.player[2], x, y);
	else if (c == 'G')
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.grinch, x, y);
}
static void	ft_put_image(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (window->map[j])
	{
		while (window->map[j][i])	
		{
			printf("dio merda\n");
			i++;
			ft_select_image(window, window->map[j][i], i * IMG_WIDTH, j * IMG_HEIGHT);
		}
		j++;
	}
}

void	ft_render(t_data *window)
{
	int	i;

	i = 32;
    window->img.exit= mlx_xpm_file_to_image(window->mlx, "img/house.xpm", &i, &i);
    window->img.wall = mlx_xpm_file_to_image(window->mlx, "img/christmas_tree.xpm", &i, &i);
    window->img.coll = mlx_xpm_file_to_image(window->mlx, "img/present.xpm", &i, &i);
    window->img.walkable= mlx_xpm_file_to_image(window->mlx, "img/snow.xpm", &i, &i);
	window->img.player[0] = mlx_xpm_file_to_image(window->mlx, "img/santa_right.xpm", &i, &i);
	window->img.player[1] = mlx_xpm_file_to_image(window->mlx, "img/santa_left.xpm", &i, &i);
	window->img.player[2] = mlx_xpm_file_to_image(window->mlx, "img/santa_front.xpm", &i, &i);
	window->img.player[3] = mlx_xpm_file_to_image(window->mlx, "img/santa_back.xpm", &i, &i);
	window->img.grinch = mlx_xpm_file_to_image(window->mlx,"img/grinch.xpm", &i, &i);
	ft_put_image(window);
}

static void	ft_map_gen(t_data *window)
{
	printf("l murt d mamt");
	int i;
	int	fd;
	printf("l murt d mamt");
	i = 0;
	fd = open("map.ber", O_RDONLY);
	window->map[i] = get_next_line(fd);
	while(window->map[i] != NULL)
		window->map[i++] = get_next_line(fd);
}
void    ft_movement(int keycode, t_coord santa_position, t_data *window, t_img img) 
{
	if (keycode == 'w' || keycode == UP)
		santa_position.y += 1;
	else if (keycode == 's' || keycode == DOWN)
		santa_position.y -= 1;
	else if (keycode == 'a' || keycode == LEFT)
		santa_position.x -= 1;
	else if (keycode == 'd' || keycode == RIGHT)
		santa_position.x += 1;
	else if (keycode == ESC)
	{
		mlx_destroy_image (window->mlx, &img);
		mlx_destroy_window (window->mlx, &window);
		mlx_destroy_display(window->mlx);
		exit (0);
	}
	else
		return ;
}

int	main(void)
{
	printf("diobestia\n");
	t_data	prova;
	prova.present = 5;
	printf("diobestia\n");
	prova.mlx = mlx_init();
	printf("sfhgksgfsk\n");
	prova.window_ptr = mlx_new_window(prova.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Prova");
	printf("dio cane\n");
	ft_map_gen(&prova);
	printf("puttana la madonna\n");
	ft_render(&prova);
	printf("puttana la madonna\n");
}
