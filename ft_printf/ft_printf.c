/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:34:26 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/28 19:34:27 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_printer(char c, va_list macro)
{
	int	erochar;

	if (c == 'c')
	{
		erochar = va_arg(macro, int);
		return (write(1, &erochar, 1));
	}
	if (c == 's')
		return (ft_putstr(va_arg(macro, char *)));
	if (c == 'p')
		return (ft_putpointer(va_arg(macro, unsigned long int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(macro, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(macro, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(macro, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex(va_arg(macro, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putstr("%"));
	return (0);
}

int	ft_printf(const char *key, ...)
{
	va_list	macro;
	int		i;
	int		leng;

	va_start(macro, key);
	i = 0;
	leng = 0;
	while (key[i])
	{
		if (key[i] == '%')
		{
			leng += arg_printer(key[i + 1], macro);
			i++;
		}
		else
			leng += write(1, &key[i], 1);
		i++;
	}
	va_end(macro);
	return (leng);
}
