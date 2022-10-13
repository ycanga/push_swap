/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:16:14 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:16:15 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			idx;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	idx = 0;
	if (dst == src || !n)
		return (dst);
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (d);
}
