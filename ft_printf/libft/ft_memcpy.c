/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:31:42 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/28 19:31:43 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*src2;
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	str = (char *)dst;
	src2 = (char *)src;
	while (i < n)
	{
		str[i] = src2[i];
		i++;
	}
	return (dst);
}
