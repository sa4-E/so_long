/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:01:16 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/28 16:31:27 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_initialise_map(char *str, t_map_info *map)
{
	if (map_reader(str, map) > 0)
	{
		ft_putstr_fd("Error\nUnable to read map\n", 2);
		return (1);
	}
	if (valid_map(map) > 0)
	{
		ft_putstr_fd("Error\nMap is not valid\n", 2);
		return (1);
	}
	if (path_check(map) > 0)
	{
		ft_putstr_fd("Error\nNo valid map-path\n", 2);
		return (1);
	}
	return (0);
}

int	play_game(char *str, t_map_info *map)
{
	if (ft_initialise_map(str, map) != 0)
		return (1);
	if (init_map_to_window(map) != 0)
		return (1);
	return (0);
}
