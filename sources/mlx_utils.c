/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:00:37 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/23 19:01:02 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_keys(int key, t_map_info *map)
{
	if (key == ESC)
	{
		mlx_loop_end(map->window);
		return (0);
	}
	return (0);
}

void	delete_images(t_map_info *map)
{
	if (map->images->portal)
		mlx_destroy_image(map->mlx, map->images->portal);
	if (map->images->rainbow)
		mlx_destroy_image(map->mlx, map->images->rainbow);
	if (map->images->cat)
		mlx_destroy_image(map->mlx, map->images->cat);
	if (map->images->empty)
		mlx_destroy_image(map->mlx, map->images->empty);
	if (map->images->wall)
		mlx_destroy_image(map->mlx, map->images->wall);
	free(map->images);
}
