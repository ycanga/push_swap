/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:13:01 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/13 16:50:52 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * İki dize alır, aralarına boşluk ekler ve sonucu döndürür
  *
  * @param s1 Birleştirilecek ilk dize.
  * @param s2, s1'e eklenecek dize
  *
  * @return Bir dizgeye işaretçi.
  */
char	*ft_strjoin_ps(char *s1, char *s2)
{
	char	*return_str;
	size_t	i;
	size_t	j;

	return_str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	i = -1;
	j = -1;
	while (s1[++i])
		return_str[i] = s1[i];
	return_str[i] = ' ';
	i++;
	while (s2[++j])
		return_str[i++] = s2[j];
	return_str[i] = '\0';
	free (s1);
	return (return_str);
}

/**
  * Komutları depolamak için kullanılacak yığınları ve dizeyi başlatır
  *
  * @param a İlk yığın.
  * @param b Sıralanan sayıları saklamak için kullanılacak yığın.
  * @param p bir karaktere bir işaretçiye işaretçi.
  * @param argv Programa iletilen argümanlar.
  */
void	init(t_stack *a, t_stack *b, char **p, char **argv)
{
	int	i;

	i = 0;
	a->size = 0;
	b->size = 0;
	*p[0] = '\0';
	while (argv[++i])
	{
		*p = ft_strjoin_ps(*p, argv[i]);
	}
}

/**
  * Bir dize alır, onu bir dizi dizeye böler, her dizeyi bir tam sayıya dönüştürür ve
  * daha sonra tamsayıları yığın dizisine koyar
  *
  * @param str bölünecek sayılar dizisi
  * @param a ilk yığın
  * @param b sıralama algoritması için kullanılacak yığın
  */
void	ft_split_stacks(char *str, t_stack *a, t_stack *b)
{
	int		i;
	int		c;
	char	**splitted;

	i = 0;
	c = 0;
	splitted = ft_split(str, ' ');
	while (splitted[i++])
		a->size++;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	i = 0;
	while (splitted[i])
	{
		a->array[i] = ft_atoi(splitted[i]);
		i++;
		c++;
	}
	b->start = b->array;
	b->array += c;
	i = 0;
	while (i < a->size)
		free(splitted[i++]);
	free(splitted);
	ft_check_repeat(a, b);
}

/**
  * Yığındaki tamsayı dizisinin bir kopyası olan geçici bir tamsayı dizisi oluşturur
  *
  * @param a sıraladığımız yığın
  *
  * @return Bir tamsayı dizisi.
  */
int	*ft_create_temp(t_stack *a)
{
	int	*temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		temp[i] = a->array[i];
		i++;
	}
	return (temp);
}

/**
  * Yığınla aynı boyutta geçici bir dizi oluşturur, sonra onu sıralar ve döndürür
  *
  * @param a sıralanacak yığın
  *
  * @return Bir tamsayı dizisi.
  */
int	*ft_sort_index(t_stack *a)
{
	int	i;
	int	j;
	int	*temp;
	int	max;

	temp = ft_create_temp(a);
	i = 0;
	while (i < a->size)
	{
		j = i;
		while (j < a->size)
		{
			if (temp[i] > temp[j])
			{
				max = temp[i];
				temp[i] = temp[j];
				temp[j] = max;
			}
			j++;
		}
		i++;
	}
	return (temp);
}
