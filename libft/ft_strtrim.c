/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:17:58 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:17:59 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_char(char c, const char *set)
{
	while (*set != '\0')
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*r;
	size_t	ep;

	if (s == NULL || set == NULL)
		return (NULL);
	while (is_char(*s, set) && *s != '\0')
		s++;
	ep = ft_strlen(s);
	while (is_char(s[ep - 1], set) && ep != 0)
		ep--;
	r = (char *)malloc(sizeof(char) * (ep + 1));
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, s, ep + 1);
	return (r);
}
