/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:42:10 by sstanfel          #+#    #+#             */
/*   Updated: 2022/12/07 20:05:22 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned int nbr, const char s)
{
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, s);
		ft_putnbr_base(nbr % 16, s);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
		{
			if (s == 'x')
				ft_putchar(nbr - 10 + 'a');
			if (s == 'X')
				ft_putchar(nbr - 10 + 'A');
		}
	}
}

static int	ft_count_hex(unsigned int nbr, const char s)
{
	int	count;

	count = 0;
	ft_putnbr_base(nbr, s);
	while (nbr)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

int	ft_put_hexa(unsigned int l, const char s)
{
	int	counter;

	counter = 0;
	if (!l)
	{
		counter += ft_putchar('0');
		return (counter);
	}
	counter += ft_count_hex(l, s);
	return (counter);
}
