/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:23:55 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/28 17:12:56 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	nu_of_rows(int fd, t_map_info *map_info)
{
	char	*line;

	map_info->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_info->rows++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	ends_with(char *mapname, char *ber)
{
	int	i;

	i = 0;
	while (mapname && mapname[i] != '\0')
		i++;
	return (ft_strncmp((mapname + i - 4), ber, 4));
}

int	read_into_array(int fd, t_map_info *map_info)
{
	int		i;
	char	*line;

	i = 0;
	map_info->map = malloc(sizeof(char *) * (map_info->rows + 1));
	if (!map_info->map)
		return (1);
	while (i < map_info->rows)
	{
		line = get_next_line(fd);
		if (line[ft_strlen(line) - 1] == '\n')
		{
			line[ft_strlen(line) - 1] = '\0';
		}
		map_info->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map_info->map[i] = NULL;
	return (0);
}

int	map_reader(char *map, t_map_info *map_info)
{
	int	fd;

	if (ends_with(map, ".ber"))
		return (1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (1);
	nu_of_rows(fd, map_info);
	close(fd);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (1);
	if (read_into_array(fd, map_info) != 0)
		return (1);
	close(fd);
	return (0);
}

// int	get_map_collums(int fd, t_map_info *map_info)
// {
// 	char	*line;
// 	int		first_line_counter;

// 	map_info->collums = 0;
// 	line = get_next_line(fd);
// 	first_line_counter = ft_strlen(line);
// 	while (line)
// 	{
// 		map_info->collums = ft_strlen(line);
// 		if (first_line_counter != map_info->collums)
// 		{
// 			free(line);
// 			return (1);
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	return (0);
// }

// int	read_map(char *map, t_map_info *map_info)
// {
// 	int	fd;

// 	// check if mapName bers in .ber
// 	// open file
// 	fd = open(map, O_RDONLY);
// 	// get number of rows
// 	get_map_rows(fd, map_info);
// 	close(fd);
// 	// get number of collums
// 	fd = open(map, O_RDONLY);
// 	if (get_map_collums(fd, map_info) != 0)
// 	{
// 		printf("Not all rows are equal in lenght\n");{

// 		return (1);
// 	}
// 	close(fd);
// 	return (0);
// }
// int	main(int argc, char **argv)
// {
// 	t_map_info	map;

// 	/* 	t_map_info	*map_pointer;
// 	map_pointer = &map;
// 	map.rows = 27;
// 	map_pointer->rows = 27; */
// 	if (argc != 2)
// 	{
// 		ft_printf("Error");
// 		return (1);
// 	}
// 	read_map(argv[1], &map);
// 	return (0);
// }