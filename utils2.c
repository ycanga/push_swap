/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:13:14 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/13 16:51:12 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * Yığındaki tamsayı dizisini alır ve dizideki her tamsayıyı dizini ile değiştirir.
  * tam sayılar
  *
  * @param bir yığın
  * @param sekmesi sıralanmış tamsayı dizisi
  */
void	ft_make_index(t_stack *a, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[i] == tab[j])
			{
				a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

/**
  * Yığındaki en küçük sayıyı bulur
  *
  * @param a yığınının pivotunu bulmak için
  *
  * @return Dizideki minimum değer.
  */
int	ft_pivot(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < a->size)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	return (min);
}

/**
  * b yığınının her bir öğesini a yığınına taşımak için gereken hamle sayısını hesaplar.
  *
  * @param a sıralanacak yığın
  * @param b sıralamaya çalıştığımız yığın
  *
  * @return Bir tamsayı dizisi.
  */
int	*ft_calc(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = malloc(sizeof(int) * b->size);
	while (i < b->size)
	{
		if (i > b->size / 2)
			tmp[i] = b->size - i;
		else
			tmp[i] = i;
		j = ft_floor(a, b->array[i], b->size + a->size);
		if (j > a->size / 2)
			j = a->size - j;
		tmp[i] += j;
		i++;
	}
	return (tmp);
}

/**
  * Verilen sayıdan büyük olan yığındaki en küçük elemanın indeksini bulur.
  *
  * @param yığındır
  * @param x katını aradığımız sayı
  * @param len yığının uzunluğu
  *
  * @return Verilen sayının katının dizini.
  */
int	ft_floor(t_stack *s, int x, int len)
{
	int	i;
	int	min;
	int	index;
	int	floor;

	i = 0;
	index = -1;
	floor = len;
	while (i < s->size)
	{
		if (x < s->array[i] && floor > s->array[i])
		{
			floor = s->array[i];
			index = i;
		}
		i++;
	}
	if (index == -1)
	{
		min = ft_pivot(s);
		index = 0;
		while (s->array[index] != min)
			index++;
	}
	return (index);
}

/**
  * Bir dizideki minimum değerin indeksini döndürür.
  *
  * @param p bir tamsayı dizisi
  * @param len dizinin uzunluğu
  *
  * @return Dizideki minimum değerin dizini.
  */
int	ft_min(int *p, int len)
{
	int	min;
	int	index;
	int	i;

	min = INT_MAX;
	i = 0;
	while (i < len)
	{
		if (p[i] < min)
		{
			min = p[i];
			index = i;
		}
		i++;
	}
	return (index);
}
