/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:11:03 by marvin@42.f       #+#    #+#             */
/*   Updated: 2023/06/13 14:06:05 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	cat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!cat)
		return (NULL);
	i = -1;
	while (s1[++i])
		cat[i] = s1[i];
	i = -1;
	while (s2[++i])
		cat[len1++] = s2[i];
	cat[len1] = '\0';
	return (cat);
}
