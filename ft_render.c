void	ft_render(t_data *window)
{
    window->img.exit= mlx_xpm_file_to_image(window->mlx, "", //casetta
			&window->size.x, &window->size.y);
    window->img.wall = mlx_xpm_file_to_image(window->mlx, "", //albero
			&window->size.x, &window->size.y);
    window->img.coll = mlx_xpm_file_to_image(window->mlx, //regalo
			"", &window->size.x, &window->size.y);
    window->img.walkable= mlx_xpm_file_to_image(window->mlx, //neve
			"", &window->size.x, &window->size.y);
	window->img.player[0] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso destra
			"", &window->size.x, &window->size.y);
	window->img.player[1] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso sinistra
			"", &window->size.x, &window->size.y);
	window->img.player[2] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso avanti
			"", &window->size.x, &window->size.y);
	window->img.player[3] = mlx_xpm_file_to_image(window->mlx, //babbo natale verso dietro
			"", &window->size.x, &window->size.y);
}