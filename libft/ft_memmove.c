/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:02:27 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/11/09 17:05:25 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s;
	char	*d;
	char	temp;

	s = (char *)src;
	d = (char *)dest;
	if (src == dest)
		return (dest);
	if (s < d)
	{
		while (len--)
		{
			temp = *(s + (len));
			*(d + (len)) = temp;
		}
		return (dest);
	}
	while (len--)
		*d++ = *s++;
	return (dest);
}
