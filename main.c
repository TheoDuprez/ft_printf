/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:43:44 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 18:38:33 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"
#include "ft_printf.c"
#include "ft_putchar.c"
#include "ft_putstr.c"
#include "ft_putnbr.c"
#include "ft_putnbr_unsign.c"
#include "ft_putnbr_base.c"
#include "ft_print_memory.c"
#include "ft_putstr_x_print_memory.c"

// #define TESTR printf(" %c %c %c ", '0', 0, '1')
// #define TESTF ft_printf(" %c %c %c ", '0', 0, '1')
// #define TESTR printf(" %d %d %d %d ", 3, 50, 12, 1234)
// #define TESTF ft_printf(" %d %d %d %d ", 3, 50, 12, 1234)
#define TESTR printf(" %p ", 156)
#define TESTF ft_printf(" %p ", 156)
// #define TESTR printf(" %d %d %d   %c ", 123, 56, 42, 'a')
// #define TESTF ft_printf(" %d %d %d   %c ", 123, 56, 42, 'a')

int	main(void)
{
	char			c = 'a';
	char			str[] = "Bonsoir";
	char 			adress = 'b';
	int				d = 500008;
	int				i = 100008155;
	unsigned int	u = 42789845;
	int				x = 4201456;
	int				x2 = 4205454;
	// TEST LEN RETURN //
	//    printf("%i\n", printf("Test1\n"));
	// printf("%i\n\n", ft_printf("Test1\n"));

	//    printf("%i\n", printf("Test2 : %c\n", c));
	// printf("%i\n\n", ft_printf("Test2 : %c\n", c));

	//    printf("%i\n", printf("Test3 : %s\n", str));
	// printf("%i\n\n", ft_printf("Test3 : %s\n", str));

	//    printf("%i\n", printf("Test4 : %p\n", &adress));
	// printf("%i\n\n", ft_printf("Test4 : %p\n", &adress));

	//    printf("%i\n", printf("Test5 : %d\n", d));
	// printf("%i\n\n", ft_printf("Test5 : %d\n", d));

	//    printf("%i\n", printf("Test6 : %i\n", i));
	// printf("%i\n\n", ft_printf("Test6 : %i\n", i));

	//    printf("%i\n", printf("Test7 : %u\n", u));
	// printf("%i\n\n", ft_printf("Test7 : %u\n", u));

	//    printf("%i\n", printf("Test8 : %x\n", x));
	// printf("%i\n\n", ft_printf("Test8 : %x\n", x));

	//    printf("%i\n", printf("Test9 : %X\n", x2));
	// printf("%i\n\n", ft_printf("Test9 : %X\n", x2));

	//    printf("%i\n", printf("Test10 : %%\n"));
	// printf("%i\n\n", ft_printf("Test10 : %%\n"));

        //   printf("%i\n", printf("Last test -> %c %s %p %d %i %u %x %X %%\n", c, str, &adress, d, i, u, x, x2));
	//  printf("%i\n\n", ft_printf("Last test -> %c %s %p %d %i %u %x %X %%\n", c, str, &adress, d, i, u, x, x2));

	//printf("%i\n", TESTR);
	//printf("%i\n", TESTF);
	// printf("%c ", '0');
	// printf("\n");
	// ft_printf("%c ", '0');
	// printf("\n");

	// write(1, NULL, 4);

	printf("Last test -> %c %s %p %d %i %u %x %X %%\n", c, str, &adress, d, i, u, x, x2);
	ft_printf("Last test -> %c %s %p %d %i %u %x %X %%\n", c, str, &adress, d, i, u, x, x2);
	return (0);
}
