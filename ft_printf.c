/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:38:48 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 18:46:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
// #include <stdarg.h>
// #include <unistd.h>
// quand printf compte la len : %d ou %s == 1 et non pas 2
// probleme de depassement de memoire a cause de i += 2 si on a seulement une len de 2 | ex : "%c", on essaye d'ecrire apres le c
#include <stdlib.h>
#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_if_forest(char next_c, int arg)
{
	int	count;

	count = 0;
	// if (next_c == 's')
	// 	count = ft_putstr(arg);
	if (next_c == 'c')
		count = ft_putchar(arg);
	else if (next_c == 'p')
		count = ft_putstr_x_print_memory(arg);
	else if (next_c == 'd')
		count = ft_putnbr(arg);
	else if (next_c == 'i')
		count = ft_putnbr(arg);
	else if (next_c == 'u')
		count = ft_putnbr_unsign(arg);
	else if (next_c == 'x')
		count = ft_putnbr_base(arg, "abcdef");
	else if (next_c == 'X')
		count = ft_putnbr_base(arg, "ABCDEF");
	else if (next_c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_print_arg(char next_c, int arg)
{
	int	count;

	count = ft_if_forest(next_c, arg);
	return (count);
}

// int	ft_is_arg(char c)
// {
// 	// if (c != '%' && (c != 's' || c != 'c' || c != 'p'
// 	// 		|| c != 'd' || c != 'd' || c != 'i' || c != 'u'
// 	// 		|| c != 'x' || c != 'X' || c != '%'))
// 	if (c != '%' && (c != 's' || c != 'c' || c != 'p'
// 			|| c != 'd' || c != 'd' || c != 'i' || c != 'u'
// 			|| c != 'x' || c != 'X' || c != '%'))
// 		return (0);
// 	return (1);
// }

int	ft_is_arg(char c, char next_c)
{
	// if (c != '%' && (c != 's' || c != 'c' || c != 'p'
	// 		|| c != 'd' || c != 'd' || c != 'i' || c != 'u'
	// 		|| c != 'x' || c != 'X' || c != '%'))
	if (c != '%' && (next_c != 's' || next_c != 'c' || next_c != 'p'
			|| next_c != 'd' || next_c != 'd' || next_c != 'i' || next_c != 'u'
			|| next_c != 'x' || next_c != 'X'))
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;
	int		count_arg_len;
	//int		res;
	char	*src;

	src = malloc(sizeof(char *) * 100);
	i = 0;
	while (s[i])
	{
		src[i] = s[i];
		i++;
	}
	src[i] = 0;
	int	len = ft_strlen(src);
	free(src);
	va_start(arg, s);
	i = 0;
	count = 0;
	count_arg_len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			//count_arg_len += ft_putchar('%');
			i++;
			count++;
		}
		else if (ft_is_arg(s[i], s[i + 1]) == 1)
		{
			if (s[i + 1] != 's')
				count_arg_len += ft_print_arg(s[i + 1], va_arg(arg, int));
			else
				count_arg_len += ft_putstr(va_arg(arg, typeof(arg)));
			i += 2;
			count += 2;
		}
		ft_putchar(s[i]);
		if (s[i] == 0)
			break ;
		i++;
	}
	va_end(arg);
	// printf("| len : [%d] [%d] [%d] | \n", count_arg_len, count, len);
	len = (len - count) + count_arg_len;
	// printf("| len : [%d] [%d] [%d] | \n", count_arg_len, count, len);
	//len -= count;
	// if (s[i - 2] == '%' && (s[i - 1] == 'c' || s[i - 1] == 's'|| s[i - 1] == 'p'|| s[i - 1] == 'i'|| s[i - 1] == 'u'|| s[i - 1] == 'x'|| s[i - 1] == 'X'|| s[i - 1] == '%'))
	// 	res -= 1;
	// printf("\nres = %d\n", res);
	// printf("\ni = %d\n", i);
	// printf("\ncount = %d\n", count);
	// printf("\ncount_arg_len = %d\n", count_arg_len);
	if (s[0] == 0)
		return (0);
	return (len);
}
