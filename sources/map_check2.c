/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:23:44 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/28 17:11:13 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nu_of_collums(t_map_info *map_info)
{
	int	first_line_counter;
	int	y;

	y = 0;
	map_info->collums = 0;
	first_line_counter = ft_strlen(map_info->map[y]);
	while (map_info->map[y])
	{
		map_info->collums = ft_strlen(map_info->map[y]);
		if (first_line_counter != map_info->collums)
		{
			return (1);
		}
		y++;
	}
	return (0);
}

int	only_allowed_char(t_map_info *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_info->rows)
	{
		x = 0;
		while (x < map_info->collums)
		{
			if (!(map_info->map[y][x] == '1' || map_info->map[y][x] == '0'
					|| map_info->map[y][x] == 'C' || map_info->map[y][x] == 'E'
					|| map_info->map[y][x] == 'P'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	num_of_allowed_char(t_map_info *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == 'C')
				map_info->collectibles++;
			if (map_info->map[y][x] == 'E')
				map_info->exit++;
			if (map_info->map[y][x] == 'P')
				map_info->player++;
			x++;
		}
		y++;
	}
	return (0);
}

int	is_wall(t_map_info *map_info)
{
	int	y;
	int	x;

	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[0][x] != '1' || map_info->map[y][map_info->collums
				- 1] != '1' || map_info->map[y][0] != '1'
				|| map_info->map[map_info->rows - 1][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	valid_map(t_map_info *map_info)
{
	if (nu_of_collums(map_info) > 0)
		return (1);
	if (only_allowed_char(map_info) > 0)
		return (1);
	if (num_of_allowed_char(map_info) > 0)
		return (1);
	if (errorhandler(map_info) > 0)
		return (1);
	if (is_wall(map_info) > 0)
		return (1);
	return (0);
}
