/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:17:45 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 17:45:28 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// Ne gere pas la len des int min et la len en cas de chiffre negatif
int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				len;
	int				count;

	nbr = nb;
	len = nb;
	count = 0;
	if (nb == 0)
		count++;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nbr *= -1;
		len *= -1;
		ft_putchar('-');
		count++;
	}
	while (len > 0)
	{
		len /= 10;
		count++;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	return (count);
}
