/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:06:55 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/10 18:40:26 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !set)
		return (NULL);
	while (*s1 && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, (j - i)));
}
