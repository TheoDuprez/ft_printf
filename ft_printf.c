/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:38:48 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/22 16:11:37 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
// #include <stdarg.h>
// #include <unistd.h>
// quand printf compte la len : %d ou %s == 1 et non pas 2
// probleme de depassement de memoire a cause de i += 2 si on a seulement -->
// --> une len de 2 | ex : "%c", on essaye d'ecrire apres le c
#include <stdlib.h>
#include "ft_printf.h"

int	ft_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_if_forest(va_list arg, char c)
{
	int	len;

	if (c == 'c')
		return (len = ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (len = ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (len = ft_putmemory((unsigned long)va_arg(arg, void *)));
	else if (c == 'd')
		return (len = ft_putnbr(va_arg(arg, int)));
	else if (c == 'i')
		return (len = ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (len = ft_putnbr_unsign(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (len = ft_putnbr_base(va_arg(arg, int), "abcdef"));
	else if (c == 'X')
		return (len = ft_putnbr_base(va_arg(arg, int), "ABCDEF"));
	else if (c == '%')
		return (len = ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	int		count;
	va_list	arg;

	i = 0;
	len = 0;
	count = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_check(s[i + 1], "cspdiuxX%%") == 1)
		{
			len += ft_if_forest(arg, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
