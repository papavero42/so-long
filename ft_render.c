/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:19:25 by pdi-pint          #+#    #+#             */
/*   Updated: 2023/12/20 16:19:27 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		mlx_put_image_to_window(window->mlx, window->window_ptr, window->img.player[2], x, y);
		window->santa_position.x = x;
		window->santa_position.y = y;
	}
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
			ft_select_image(window, window->map[j][i], i * IMG_WIDTH, j * IMG_HEIGHT);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_render(t_data *window)
{
	int	i;

	i = 32;
    window->img.exit= mlx_xpm_file_to_image(window->mlx, "img/house.xpm", &i, &i);
    window->img.wall = mlx_xpm_file_to_image(window->mlx, "img/christmas_tree.xpm", &i, &i);
    window->img.coll = mlx_xpm_file_to_image(window->mlx, "img/present1.xpm", &i, &i);
    window->img.walkable= mlx_xpm_file_to_image(window->mlx, "img/snow.xpm", &i, &i);
	window->img.player[0] = mlx_xpm_file_to_image(window->mlx, "img/santa_right.xpm", &i, &i);
	window->img.player[1] = mlx_xpm_file_to_image(window->mlx, "img/santa_left.xpm", &i, &i);
	window->img.player[2] = mlx_xpm_file_to_image(window->mlx, "img/santa_front.xpm", &i, &i);
	window->img.player[3] = mlx_xpm_file_to_image(window->mlx, "img/santa_back.xpm", &i, &i);
	window->img.grinch = mlx_xpm_file_to_image(window->mlx,"img/grinch.xpm", &i, &i);
	ft_put_image(window);
}

int	rows_alloc(t_data *window)
{
	int		fd;
	int		row_count;
	char	char_check;
	void	*char_ptr;


	row_count = 1;
	char_ptr = &char_check;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, char_ptr, 1) != 0)
	{
		if (char_check == '\n')
			row_count++;
	}
	close(fd);
	window->map = malloc(sizeof(char *) * row_count);
	return (row_count);
}

int	ft_map_gen(t_data *window)
{
	int	fd;
	int	i;
	int row_count;

	i = 0;
	row_count = rows_alloc(window);
	if (!window->map)
		return (-1);
	fd = open("map.ber", O_RDONLY);
	while (i < row_count)
	{
		window->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

 void    ft_movement(int keycode, t_data *window)
 {
	ft_select_image(window, '0', window->santa_position.y * IMG_WIDTH, window->santa_position.x * IMG_HEIGHT);
 	if (keycode == 'w' || keycode == UP)
 		window->santa_position.y += 1;
 	else if (keycode == 's' || keycode == DOWN)
 		window->santa_position.y -= 1;
 	else if (keycode == 'a' || keycode == LEFT)
 		window->santa_position.x -= 1;
 	else if (keycode == 'd' || keycode == RIGHT)
 		window->santa_position.x += 1;
	ft_select_image(window, 'P', window->santa_position.y * IMG_WIDTH, window->santa_position.x * IMG_HEIGHT);
 	if (keycode == ESC)
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
	t_data	prova;
	prova.present = 5;
	prova.mlx = mlx_init();
	if (!prova.mlx)
		return (free(prova.mlx), 1);
	prova.window_ptr = mlx_new_window(prova.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Prova");
	ft_map_gen(&prova);
	ft_render(&prova);
	mlx_hook(&prova)
	mlx_loop(&prova);
}
