/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:22 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/23 16:00:33 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	if_duplicates(t_map_info *map_info)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (map_info->map[y])
	{
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == 'P')
				c++;
			if (map_info->map[y][x] == 'E')
				c++;
			x++;
		}
		x = 0;
		y++;
	}
	if (c != 2)
		return (1);
	return (0);
}

int	errorhandler(t_map_info *map_info)
{
	if (map_info->collectibles < 1)
		return (1);
	if (map_info->exit != 1)
		return (1);
	if (map_info->player != 1)
		return (1);
	return (0);
}

void	player_pos(t_map_info *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == 'P')
			{
				map_info->player_x = x;
				map_info->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
