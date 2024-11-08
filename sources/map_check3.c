/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:59:34 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/23 19:01:01 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	malloc_temp_map(t_map_info *map_info)
{
	int	y;

	y = 0;
	map_info->temp_map = malloc(sizeof(char *) * (map_info->rows + 1));
	if (!map_info->temp_map)
		return (1);
	while (y < map_info->rows)
	{
		map_info->temp_map[y] = ft_strdup(map_info->map[y]);
		y++;
	}
	map_info->temp_map[map_info->rows] = NULL;
	return (0);
}

void	fill(t_map_info *map_info, int y, int x)
{
	if (x < 0 || y < 0 || x > map_info->collums - 1 || y > map_info->rows - 1)
		return ;
	if (map_info->temp_map[y][x] == '1' || map_info->temp_map[y][x] == 'F')
		return ;
	if (map_info->temp_map[y][x] == 'E')
	{
		map_info->temp_map[y][x] = 'F';
		return ;
	}
	map_info->temp_map[y][x] = 'F';
	fill(map_info, y + 1, x);
	fill(map_info, y - 1, x);
	fill(map_info, y, x + 1);
	fill(map_info, y, x - 1);
}

int	is_fully_flooded(t_map_info *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map_info->temp_map[y])
	{
		x = 0;
		while (map_info->temp_map[y][x])
		{
			if (map_info->temp_map[y][x] == 'E'
				|| map_info->temp_map[y][x] == 'C'
				|| map_info->temp_map[y][x] == 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	path_check(t_map_info *map_info)
{
	if (malloc_temp_map(map_info) > 0)
		return (1);
	player_pos(map_info);
	fill(map_info, map_info->player_y, map_info->player_x);
	if (is_fully_flooded(map_info) > 0)
		return (1);
	return (0);
}

// void print_tempE_map(t_map_info *map_info)
// {
//     int x;
//     x = -1;
//     while (map_info->temp_map[++x])
//     {
//         printf("%s\n", map_info->temp_map[x]);
//     }
// }