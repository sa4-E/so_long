/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:44:21 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/28 16:51:00 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DWN 65364
# define LE 65361
# define RI 65363
# define ESC 65307

typedef struct s_images
{
	void		*portal;
	void		*rainbow;
	void		*cat;
	void		*empty;
	void		*wall;
}				t_images;

typedef struct s_map_info
{
	char		**map;
	char		**temp_map;
	int			rows;
	int			collums;
	int			collectibles;
	int			exit;
	int			player;
	int			player_y;
	int			player_x;
	int			move;
	void		*mlx;
	void		*window;
	t_images	*images;

}				t_map_info;

//free_exit.c
void			free_2d_array(char **array);
void			free_exit(t_map_info *map);
void			*free_set_null(void *p);
int				exit_game(t_map_info *map);
//main.c
void			init_map(t_map_info *map);
//map_check_utils
int				if_duplicates(t_map_info *map_info);
int				errorhandler(t_map_info *map_info);
void			player_pos(t_map_info *map_info);
// map_check1
void			nu_of_rows(int fd, t_map_info *map_info);
int				ends_with(char *str, char *end);
int				read_into_array(int fd, t_map_info *map_info);
int				map_reader(char *map, t_map_info *map_info);
//map_check2
int				nu_of_collums(t_map_info *map_info);
int				only_allowed_char(t_map_info *map_info);
int				num_of_allowed_char(t_map_info *map_info);
int				is_wall(t_map_info *map_info);
int				valid_map(t_map_info *map_info);
//map_check3
int				malloc_temp_map(t_map_info *map_info);
void			fill(t_map_info *map_info, int y, int x);
int				is_fully_flooded(t_map_info *map_info);
int				path_check(t_map_info *map_info);
//mlx_utils.c
int				ft_keys(int key, t_map_info *map);
void			delete_images(t_map_info *map);
//mlx
int				init_map_to_window(t_map_info *map);
void			ft_put_window1(t_map_info *game);
void			ft_put_window1(t_map_info *game);
void			image_init(t_map_info *game);
void			ft_put_image_to_window(t_map_info *game);
//movement.c
int				key_press(int key, t_map_info *game);
void			move(t_map_info *game, int y, int x);
//play_game.c
int				ft_initialise_map(char *str, t_map_info *map);
int				play_game(char *str, t_map_info *map);

#endif
