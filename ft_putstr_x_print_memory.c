/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_x_print_memory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:12:17 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 17:45:31 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putstr_x_print_memory(unsigned int arg)
// {
// 	int	count;

// 	count = 0;
// 	count += ft_putstr("0x7ffe");
// 	count += ft_print_memory(arg, "abcdef");
// 	count += 6;
// 	return (count);
// }

int	ft_putstr_x_print_memory(unsigned int arg)
{
	int	count;

	count = 0;
	if (sizeof(arg) != sizeof(void *))
		count += ft_putstr("0x");
	count += ft_print_memory(arg, "abcdef");
	return (count - 1);
}