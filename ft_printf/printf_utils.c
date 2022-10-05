/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:34:40 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/28 19:34:41 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_putstr(char *str)
{
	char	*mem;

	if (!str)
		return (ft_putstr("(null)"));
	mem = str;
	while (*str)
		write(1, str++, 1);
	return (str - mem);
}

int	ft_putpointer(unsigned long int point)
{
	char	str[16];
	int		i;
	int		leng;

	if (point == 0)
		return (ft_putstr("0x0"));
	leng = ft_putstr("0x");
	ft_bzero(str, 16);
	i = 0;
	while (point)
	{
		str[i++] = "0123456789abcdef"[point % 16];
		point /= 16;
	}
	while (i--)
		leng += write(1, &str[i], 1);
	return (leng);
}

int	ft_puthex(unsigned int point, char *charset)
{
	char	str[16];
	int		i;
	int		leng;

	if (point == 0)
		return (ft_putstr("0"));
	ft_bzero(str, 16);
	i = 0;
	leng = 0;
	while (point)
	{
		str[i] = charset[point % 16];
		point /= 16;
		i++;
	}
	while (i--)
		leng += write(1, &str[i], 1);
	return (leng);
}

int	ft_putnbr(int nb)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nb);
	len += ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putunsigned(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_putunsigned(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	i++;
	return (i);
}
