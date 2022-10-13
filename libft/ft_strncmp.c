/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:17:43 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:17:44 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (s1[a] && s2[a] && s1[a] == s2[a] && a < n)
		a++;
	if (a == n)
		return (0);
	return (((unsigned char)s1[a]) - ((unsigned char)s2[a]));
}	
