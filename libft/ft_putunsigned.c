/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:42:17 by sstanfel          #+#    #+#             */
/*   Updated: 2022/11/25 21:51:37 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_int( int n)
{
	unsigned int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(unsigned int n)
{
	char			*s;
	unsigned int	count;
	unsigned int	i;

	count = count_int(n);
	i = n;
	s = malloc(count_int(n) + 1);
	if (!s)
		return (0);
	while (count > 0)
	{
		s[count - 1] = n % 10 + '0';
		n = n / 10;
		count--;
	}
	s[count_int(i)] = '\0';
	return (s);
}

int	ft_putunsigned(unsigned int i)
{
	unsigned int	c;
	char			*ptr;

	ptr = ft_itoa(i);
	c = ft_putstr(ptr);
	free(ptr);
	return (c);
}
