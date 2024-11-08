/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:03:54 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/28 17:22:11 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_map_to_window(t_map_info *map)
{
	map->mlx = mlx_init();
	if (!(map->mlx))
	{
		ft_putstr_fd("Error\n Unable to initalize window\n", 2);
		return (1);
	}
	map->window = mlx_new_window(map->mlx, (map->collums * 64), (map->rows
				* 64), "lol funny map xdd");
	if (!map->window)
		exit_game(map);
	image_init(map);
	ft_put_image_to_window(map);
	mlx_hook(map->window, 2, (1L << 0), key_press, map);
	mlx_hook(map->window, 17, 0L, exit_game, map);
	mlx_loop(map->mlx);
	return (0);
}

void	image_init(t_map_info *game)
{
	int	i;

	game->images = malloc(sizeof(t_images));
	game->images->empty = mlx_xpm_file_to_image(game->mlx,
			"./img/empty.xpm", &i, &i);
	game->images->cat = mlx_xpm_file_to_image(game->mlx,
			"./img/player.xpm", &i, &i);
	game->images->rainbow = mlx_xpm_file_to_image(game->mlx,
			"./img/collectible.xpm", &i, &i);
	game->images->portal = mlx_xpm_file_to_image(game->mlx,
			"./img/portal.xpm", &i, &i);
	game->images->wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &i, &i);
	if (!(game->images->empty) || !(game->images->cat)
		|| !(game->images->rainbow) || !(game->images->portal)
		|| !(game->images->wall))
	{
		ft_printf("Error\nImages are not correcly initialized\n");
		exit_game(game);
	}
}

void	ft_put_window1(t_map_info *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images->cat, (x * 64), (y * 64));
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images->rainbow, (x * 64), (y * 64));
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images->wall, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

void	ft_put_window2(t_map_info *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images->portal, (x * 64), (y * 64));
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images->empty, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

void	ft_put_image_to_window(t_map_info *game)
{
	ft_put_window1(game);
	ft_put_window2(game);
}
