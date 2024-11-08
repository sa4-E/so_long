/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <sstanfel>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:56:47 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/10/26 01:56:59 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	size_t	k;

	k = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (src[k] && k + 1 < size)
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
	return (ft_strlen((char *)src));
}

// int	main(void)
// {
// 	size_t i = 0;
// 	char dest[7] = "123haha";
// 	i = ft_strlcpy(dest, "lorem ipsum", 3);

// 	printf("%ld shit head please stop %s", i, dest);
// }