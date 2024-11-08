/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:24:51 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/04 19:55:15 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*lululu;
	unsigned int	l;

	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	lululu = malloc(sizeof(char) * (len + 1));
	if (!lululu)
		return (NULL);
	l = 0;
	while (l < len && s[start + l])
	{
		lululu[l] = s[start + l];
		l++;
	}
	lululu[l] = '\0';
	return (lululu);
}
