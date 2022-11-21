/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:45:09 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 17:45:21 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_putnbr_base(int nb, char *charset)
// {
// 	unsigned int	nbr;
// 	int				i;

// 	nbr = nb;
// 	i = 0;
// 	if (nb < 0)
// 	{
// 		nbr *= -1;
// 		ft_putchar('-');
// 	}
// 	if (nbr >= 16)
// 		ft_putnbr_base(nbr / 16, charset);
// 	if (nbr % 16 >= 10)
// 	{
// 		ft_putchar(charset[nbr % 16 - 10]);
// 		i++;
// 	}
// 	else
// 	{
// 		ft_putchar(nbr % 16 + '0');
// 		i++;
// 	}
// 	return ;
// }

int	ft_putnbr_base(unsigned int nb, char *charset)
{
	unsigned int	nbr;
	unsigned int				len;
	unsigned int				count;

	nbr = nb;
	len = nb;
	count = 0;
	if (len == 0)
		count++;
	if (nb < 0)
	{
		nbr *= -1;
		len *= -1;
		ft_putchar('-');
		count++;
	}
	while (len > 0)
	{
		len /= 16;
		count++;
	}
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, charset);
	if (nbr % 16 >= 10)
		ft_putchar(charset[nbr % 16 - 10]);
	else
		ft_putchar(nbr % 16 + '0');
	return (count);
}

// void	ft_putnbr(int nb)
// {
// 	unsigned int	nbr;

// 	nbr = nb;
// 	if (nb < 0)
// 	{
// 		nbr *= -1;
// 		ft_putchar('-');
// 	}
// 	if (nbr > 9)
// 	{
// 		ft_putnbr(nbr / 10);
// 	}
// 	ft_putchar((nbr % 10) + '0');
// }
