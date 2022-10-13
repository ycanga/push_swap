/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:18:51 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:18:52 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select(va_list args, const char select)
{
	int	count;

	count = 0;
	if (select == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (select == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (select == 'p')
		count += ft_hex(va_arg(args, unsigned long), "0123456789abcdef", 1, 16);
	else if (select == 'd' || select == 'i')
		count += ft_print_number(va_arg(args, int));
	else if (select == 'u')
		count += ft_print_unumber(va_arg(args, unsigned int));
	else if (select == 'x')
		count += ft_hex(va_arg(args, unsigned), "0123456789abcdef", 0, 16);
	else if (select == 'X')
		count += ft_hex(va_arg(args, unsigned), "0123456789ABCDEF", 0, 16);
	else if (select == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &select, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		c;
	int		print_count;
	va_list	args;

	c = 0;
	print_count = 0;
	va_start(args, str);
	while (str[c])
	{
		if (str[c] == '%')
		{
			print_count += ft_select(args, str[c + 1]);
				c++;
		}
		else
			print_count += ft_print_char(str[c]);
		c++;
	}
	va_end(args);
	return (print_count);
}
