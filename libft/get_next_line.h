/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:12:27 by sstanfel          #+#    #+#             */
/*   Updated: 2023/07/11 19:47:16 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*buff_in_pot(char *hold, int fd);
char	*complete_line(char *hold);

/*get_next_line_utils*/
size_t	ft_strlen(const char *str);
char	*ft_strjoint(char *s1, char const *s2);
char	*ft_gstrchr(const char *s, int c);
#endif
