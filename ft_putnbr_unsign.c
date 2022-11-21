/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:28:29 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 17:45:25 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsign(unsigned int nb)
{
	unsigned int	nbr;
	int				len;
	int				count;

	nbr = nb;
	len = nb;
	count = 0;
	if (len == 0)
		count++;
	if ((int)nb < 0)
	{
		count = 10;
	}
	while (len > 0)
	{
		len /= 10;
		count++;
	}
	if (nbr > 9)
		ft_putnbr_unsign(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	return (count);
}
