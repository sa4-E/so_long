/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:40:16 by sstanfel          #+#    #+#             */
/*   Updated: 2022/10/24 16:27:21 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ps;
	char	*pd;

	i = 0;
	ps = (char *)src;
	pd = (char *)dest;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		*(pd + i) = *(ps + i);
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "mahmudulhasanjony";
// 	char dest[];
// 	char *ret;

// 	ret = ft_memcpy(dest, src, 9);
// 	printf("%s", ret);
// 	return (0);
// }