/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:32:21 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/28 19:32:22 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
			i++;
		while (*s && *s != c)
			s++;
		if (*s && *s == c)
			s++;
	}
	return (i);
}

int	ft_errorcheck(const char *s, size_t *count, char c, char ***str)
{
	if (!s)
		return (0);
	*count = ft_wordcount(s, c);
	*str = malloc ((*count + 1) * sizeof(char *));
	if (!*str)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	count;

	if (!ft_errorcheck (s, &count, c, &str))
		return (NULL);
	j = 0;
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i != 0 && j < count)
		{
			str[j] = ft_substr (s, 0, i);
			j++;
		}
		s += i + 1;
	}
	str[count] = NULL;
	return (str);
}
