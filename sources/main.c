/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:44:18 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/28 16:47:04 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_map_info *map)
{
	map->map = NULL;
	map->temp_map = NULL;
	map->rows = 0;
	map->collums = 0;
	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->move = 0;
	map->images = NULL;
	map->mlx = NULL;
	map->window = NULL;
}

int	main(int argc, char **argv)
{
	t_map_info	*map;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of args!\n", 2);
		return (1);
	}
	map = malloc(sizeof(t_map_info));
	if (!map)
		return (1);
	init_map(map);
	if (play_game(argv[1], map) != 0)
		exit_game(map);
	return (0);
}
