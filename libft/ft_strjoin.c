/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:17:17 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:17:18 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	s;

	s = 0;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		p[s] = *(char *)s1;
		s1++;
		s++;
	}
	while (*s2 != '\0')
	{
		p[s] = *(char *)s2;
		s2++;
		s++;
	}
	p[s] = '\0';
	return (p);
}		
