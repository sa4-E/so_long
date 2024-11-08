/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <sstanfel>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:06:30 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/10/26 02:40:53 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*shgiet;

	shgiet = malloc(count * size);
	if (!shgiet)
		return (NULL);
	ft_bzero(shgiet, count * size);
	return (shgiet);
}
