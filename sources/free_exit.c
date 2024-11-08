/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:37:06 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/23 19:37:08 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*free_set_null(void *p)
{
	if (p != NULL)
		free(p);
	p = NULL;
	return (p);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
// void	free_exit(t_map_info *map)
// {
// 	if (map->map)
// 		free_2d_array(map->map);
// 	if (map->temp_map)
// 		free_2d_array(map->temp_map);
// 	free(map->map);
// 	free(map);
// }

int	exit_game(t_map_info *map)
{
	if (map)
	{
		if (map->map)
			free_2d_array(map->map);
		if (map->temp_map)
			free_2d_array(map->temp_map);
		if (map->images)
			delete_images(map);
		if (map->window)
		{
			mlx_destroy_window(map->mlx, map->window);
		}
		if (map->mlx)
		{
			mlx_destroy_display(map->mlx);
			free_set_null(map->mlx);
		}
	}
	free_set_null(map);
	exit(0);
	return (0);
}
