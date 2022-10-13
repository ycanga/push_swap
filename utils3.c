/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:36:29 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:13:20 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * A yığınını, B yığınının ilk elemanı A yığınının en üstünde olacak şekilde döndürür.
  *
  * @param a sıraladığımız yığın
  * @param b sıralamaya çalıştığımız yığın
  */
void	ft_pre_a(t_stack*a, t_stack *b)
{
	int	len;
	int	sup;

	len = ft_floor(a, b->array[0], b->size + a->size);
	sup = 1;
	if (len > a->size / 2)
	{
		len = a->size - len;
		sup = 0;
	}
	while (len--)
	{
		if (!sup)
			ft_rra(a, 1);
		else
			ft_ra(a, 1);
	}
}

/**
  * En küçük eleman en üstte olacak şekilde b yığınını döndürür
  *
  * @param b yığını
  * @param p ögenin yığındaki konumu
  *
  * @return Son değer döndürülüyor.
  */
int	ft_pre_b(t_stack *b, int *p)
{
	int	len;
	int	sup;
	int	end;

	sup = 1;
	len = ft_min(p, b->size);
	end = len;
	if (len > b->size / 2)
	{
		len = b->size - len;
		sup = 0;
	}
	while (len--)
	{
		if (!sup)
			ft_rrb(b);
		else
			ft_rb(b);
	}
	return (end);
}

/**
  * Yığın a ve yığın b'yi alır ve ardından yığın a'nın medyanını hesaplar ve sonra iter
  * medyandan daha küçük olan değerler b yığınına ve daha sonra daha büyük olan değerleri iter
  * a yığınına medyandan daha fazla ve ardından medyana eşit olan değerleri a yığınına iter
  *
  * @param a sıralanacak yığın
  * @param b sıralanan yığın
  */
void	ft_helper(t_stack *a, t_stack *b)
{
	int	*temp;

	temp = ft_calc(a, b);
	ft_pre_b(b, temp);
	free(temp);
	ft_pre_a(a, b);
	ft_pa(a, b, 1);
}

/**
  * Yığınlar için ayrılan belleği boşaltır ve programdan çıkar
  *
  * @param a ilk yığın
  * @param b sayıları tutan yığın
  */
void	ft_free(t_stack *a, t_stack *b)
{
	b->array = b->start;
	free(b->array);
	free(b);
	free(a->array);
	free(a);
	exit (0);
}
