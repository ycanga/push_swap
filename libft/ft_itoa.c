/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:14:20 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:14:21 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_len(long src)
{
	int	i;

	i = 0;
	if (src == 0)
		return (1);
	if (src < 0)
		i++;
	while (src)
	{
		src /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	num;

	num = n;
	i = ft_len(num);
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		num *= -1;
		ret[0] = '-';
	}
	ret[i] = 0;
	i--;
	while (i >= (n < 0))
	{
		ret[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (ret);
}
