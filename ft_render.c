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

char	*ft_freejoin(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	return (temp);
}

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
	while (window->map[i][j])
	{
		while (window->map[i++][j++])
			ft_select_image(window, window->map[i][j], i * IMG_WIDTH, j * IMG_HEIGHT);
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

/* static void	ft_map_gen(t_data *window)
{
	int i;
	int j;
	int	fd;
	j = 0;
	i = 0;
	fd = open("map.ber", O_RDONLY);
	window->map[0]= get_next_line(fd);
	while(window->map[i] != NULL)
	{
		window->map[i] = get_next_line(fd);
		i++;
		j++;
	}
} */

char	**ft_map_gen(char **map)
{
	char	*buffer;
	char	*line;
	int		fd_open;

	map = NULL;
	fd_open = open("map.ber", O_RDONLY);
	/*if (fd_open == -1)
		ft_error("MAP DOES NOT EXIST", NULL);*/
	buffer = malloc(1);
	buffer[0] = 0;
	if (!buffer)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd_open);
		if (!line)
			break ;
		buffer = ft_freejoin(buffer, line);
	}
	map = ft_split(buffer, '\n');
	//ft_collectable_count(map, window);
	free(buffer);
	return (map);
}

// void    ft_movement(int keycode, t_coord santa_position, t_data *window, t_img img)
// {
// 	if (keycode == 'w' || keycode == UP)
// 		santa_position.y += 1;
// 	else if (keycode == 's' || keycode == DOWN)
// 		santa_position.y -= 1;
// 	else if (keycode == 'a' || keycode == LEFT)
// 		santa_position.x -= 1;
// 	else if (keycode == 'd' || keycode == RIGHT)
// 		santa_position.x += 1;
// 	else if (keycode == ESC)
// 	{
// 		mlx_destroy_image (window->mlx, &img);
// 		mlx_destroy_window (window->mlx, &window);
// 		mlx_destroy_display(window->mlx);
// 		exit (0);
// 	}
// 	else
// 		return ;
// }

int	main(void)
{
	t_data	prova;
	prova.present = 5;
	prova.mlx = mlx_init();
	if (!prova.mlx)
		return (free(prova.mlx), 1);
	prova.window_ptr = mlx_new_window(prova.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Prova");
	printf("ffffffffffffffff\n");
	printf("%p", &prova);
	printf("%p", &prova);
	printf("ssssssssssssssss\n");
	ft_render(&prova);
	printf("dddddddddddddddddd\n");
}

