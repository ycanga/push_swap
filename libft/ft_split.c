/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:16:52 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:16:53 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordl(const char *s, char c, int l)
{
	size_t	i;

	i = 0;
	if (l)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	else
	{
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static size_t	ft_wordc(const char *str, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != c)
			i++;
		wc++;
		while (str[i] != '\0' && str[i] == c)
			i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	wc;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	wc = ft_wordc(s, c);
	str = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!str)
		return (NULL);
	while (i < wc)
	{
		s += ft_wordl(s, c, 0);
		str[i] = ft_substr(s, 0, ft_wordl(s, c, 1));
		if (!str)
			return (NULL);
		s += ft_wordl(s, c, 1) + ft_wordl(s, c, 0);
		i++;
	}
	str[i] = NULL;
	return (str);
}
