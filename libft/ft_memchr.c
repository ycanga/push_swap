/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:16:02 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:16:03 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	a;
	size_t			counter;

	counter = 0;
	src = (unsigned char *)s;
	a = (unsigned char)c;
	while (n > counter)
	{
		if (*src == a)
			return (src);
		src++;
		n--;
	}
	return (NULL);
}
