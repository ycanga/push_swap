/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:12:07 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:12:08 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * En büyük sayı birinci konumdaysa, yığını ikinci en büyük sayı gelene kadar döndürün.
  * ilk konumda, ardından ilk iki sayıyı değiştirin. En büyük sayı ikinci ise
  * konumuna getirin, yığını en küçük sayı ilk konuma gelene kadar döndürün, ardından ilkini değiştirin
  * iki sayı. En büyük sayı üçüncü konumdaysa, ilk iki sayıyı değiştirin
  *
  * @param bir yığın
  */
void	ft_swap_trois(t_stack *a)
{
	if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
	{
		if (a->array[1] < a->array[2])
			ft_rra(a, 2);
		else
		{
			ft_sa(a);
			ft_rra(a, 1);
		}
	}
	else if (a->array[1] > a->array[0] && a->array[1] > a->array[2])
	{
		if (a->array[0] > a->array[2])
			ft_rra(a, 1);
		else
		{
			ft_rra(a, 1);
			ft_sa(a);
		}
	}
	else if (a->array[2] > a->array[1] && a->array[2] > a->array[0])
		if (a->array[1] < a->array[0])
			ft_sa(a);
}

/**
  * Son eleman en küçükse, yığını bir kez döndürün. Son eleman en büyükse, değiştirin
  * ilk iki element. Son eleman ortadaysa, son elemanı ikinciye itin.
  * yığın, ilk iki öğeyi değiştirin ve son öğeyi ilk yığına geri itin
  *
  * @param a ilk yığın
  * @param b ittiğimiz yığın
  */
void	ft_swap_quatre(t_stack *a, t_stack *b)
{
	ft_pb(a, b, 1);
	ft_swap_trois(a);
	ft_pa(a, b, 1);
	ft_ra(a, 1);
	if (a->array[3] > a->array[1])
	{
		if (a->array[3] < a->array[2])
		{
			ft_pb(a, b, 2);
			ft_sa(a);
			ft_pa(a, b, 2);
		}
	}
	else
	{
		if (a->array[3] < a->array[0])
			ft_rra(a, 1);
		else
		{
			ft_rra(a, 1);
			ft_sa(a);
		}
	}
}

/**
  * Yığındaki en küçük sayıyı bulur, en üste taşır, sonra sıralayan işlevi çağırır.
  * ilk dört sayı
  *
  * @param a ilk yığın
  * @param b ittiğimiz yığın
  */
void	ft_swap_cinq(t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	index = 0;
	min = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] < min)
		{
			index = i;
			min = a->array[i];
		}
		i++;
	}
	if (a->size / 2 <= index)
		while (a->array[0] != min)
			ft_rra(a, 1);
	else
		while (a->array[0] != min)
			ft_ra(a, 1);
	ft_pb(a, b, 1);
	ft_swap_quatre(a, b);
	ft_pa(a, b, 1);
}

/**
  * Yığını sıralar, ardından en küçük öğeyi yığının en üstüne iter
  *
  * @param a ilk yığın
  * @param b sıralanacak yığın
  */
void	ft_sort_plus(t_stack *a, t_stack *b)
{
	int	*tab;

	tab = ft_sort_index(a);
	ft_make_index(a, tab);
	free(tab);
	ft_push_b(a, b);
	ft_push_a(a, b);
}
