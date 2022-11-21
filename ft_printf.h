/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:55:53 by tduprez           #+#    #+#             */
/*   Updated: 2022/11/18 18:13:50 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int nb);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_printf(const char *s, ...);
int	ft_putnbr_unsign(unsigned int nb);
int	ft_putnbr_base(unsigned int nb, char *charset);
int	ft_putstr_x_print_memory(unsigned int arg);
int	ft_print_arg(char next_c, int arg);
int	ft_print_memory(unsigned int nb, char *charset);

#endif
