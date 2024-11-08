/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:20:16 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/10/24 16:26:39 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = '\0';
}
// int	main(void)
// {
// 	char s[] = "pipikakaland";
// 	printf("Before: %s\n", s);
// 	ft_bzero(s, 13);
// 	printf("After: %s", s);
// }