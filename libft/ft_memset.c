/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:23:31 by sstanfel          #+#    #+#             */
/*   Updated: 2022/10/24 16:27:26 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*str_arr;

	str_arr = (unsigned char *)b;
	while (n--)
		*str_arr++ = c;
	return (b);
}
// int	main(void)
// {
// 	char str[50] = "Yannis ist kein Frauenschläger";
// 	printf("\nBefore memset(): %s\n", str);

// 	ft_memset(str + 11, 32, 1 * sizeof(char));

// 	printf("After memset():  %s", str);
// 	return (0);
// }