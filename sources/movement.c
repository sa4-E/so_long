/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:44:44 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/23 19:13:04 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int key, t_map_info *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if ((key == 'W' || key == UP) && (game->map[y - 1][x] != '1'))
		move(game, y - 1, x);
	else if ((key == 'A' || key == LE) && (game->map[y][x - 1] != '1'))
		move(game, y, x - 1);
	else if ((key == 'S' || key == DWN) && (game->map[y + 1][x] != '1'))
		move(game, y + 1, x);
	else if ((key == 'D' || key == RI) && (game->map[y][x + 1] != '1'))
		move(game, y, x + 1);
	else if (key == ESC)
		exit_game(game);
	return (0);
}

void	move(t_map_info *game, int y, int x)
{
	int	old_y;
	int	old_x;

	old_y = game->player_y;
	old_x = game->player_x;
	if (game->map[y][x] == 'E' && !(game->collectibles))
	{
		exit_game(game);
		game->move++;
		ft_printf("Move:%i\n", game->move);
	}
	else if (game->map[y][x] == 'E')
		;
	else if (game->map[old_y][old_x] == 'P')
	{
		if (game->map[y][x] == 'C')
			game->collectibles--;
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->map[old_y][old_x] = '0';
		game->move++;
		ft_printf("Move:%i\n", game->move);
	}
	ft_put_image_to_window(game);
}
