/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:25:58 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 17:45:07 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(unsigned int nb, char *charset)
{
	int	count;

	count = 0;
	if (nb >= 16)
		ft_print_memory(nb / 16, charset);
	if (nb % 16 >= 10)
	{
		ft_putchar(charset[nb % 16 - 10]);
		count++;
	}
	else
	{
		ft_putchar(nb % 16 + '0');
		count++;
	}
	return (count + 1);
}
