/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:13:25 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:13:26 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		numb = (str[i++] - '0') + (numb * 10);
	if ((numb * sign) > 2147483647 || (numb * sign) < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (numb * sign);
}
