/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstanfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:23:41 by sstanfel          #+#    #+#             */
/*   Updated: 2022/12/07 20:05:12 by sstanfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16);
		ft_putnbr_base(nbr % 16);
	}
	else
	{
		if (nbr < 9)
			ft_putchar(nbr + '0');
		if (nbr >= 10)
			ft_putchar(nbr - 10 + 'a');
	}
}

static int	ft_put_hex(unsigned long long nbr)
{
	int	count;

	count = 0;
	ft_putnbr_base(nbr);
	while (nbr)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count);
}

int	ft_putptr(unsigned long long l)
{
	int	counter;

	counter = 0;
	if (!l)
	{
		counter += ft_putstr("(nil)");
		return (counter);
	}
	counter += ft_putstr("0x");
	counter += ft_put_hex(l);
	return (counter);
}
