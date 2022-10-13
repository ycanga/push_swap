/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:12:31 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/13 11:33:00 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * Yığının ilk iki öğesini değiştirin. Yalnızca bir öğe varsa veya hiç öğe yoksa hiçbir şey yapmayın
  *
  * @param a İlk iki öğesini değiştireceğimiz yığın.
  */
void	ft_sa(t_stack *a)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = temp;
		ft_printf("sa\n");
	}
}

/**
  * Dizinin son elemanını alır ve başına koyar
  *
  * @param a döndürülecek yığın
  * @param c yığını döndürme sayısı
  */
void	ft_rra(t_stack *a, int c)
{
	int	i;
	int	tmp;

	while (c--)
	{
		i = a->size;
		if (i >= 2)
		{
			tmp = a->array[a->size - 1];
			while (i > 1)
			{
				a->array[i - 1] = a->array[i - 2];
				i--;
			}
			a->array[0] = tmp;
			ft_printf("rra\n");
		}
	}
}

/**
  * A yığınının ilk elemanını alır ve onu b yığınının başına koyar.
  *
  * @param a İlk yığın
  * @param b itilecek yığın
  * @param c kaç kez basılacak
  *
  * @yığındaki öğelerin sayısını döndürür.
  */
void	ft_pb(t_stack *a, t_stack *b, int c)
{
	while (c--)
	{
		if (a->size <= 0)
			return ;
		b->array--;
		b->array[0] = a->array[0];
		b->size++;
		a->size--;
		a->array++;
		ft_printf("pb\n");
	}
}

/**
  * İkinci yığının ilk elemanını alır ve ilk yığının başına koyar.
  *
  * @param ilk yığına bir işaretçi
  * @param b itilecek yığın
  * @param c işlemi gerçekleştirme sayısı
  *
  * @yığındaki öğelerin sayısını döndürür.
  */
void	ft_pa(t_stack *a, t_stack *b, int c)
{
	while (c--)
	{
		if (b->size <= 0)
			return ;
		a->array--;
		a->array[0] = b->array[0];
		a->size++;
		b->size--;
		b->array++;
		ft_printf("pa\n");
	}
}

/**
  * Dizinin ilk elemanını alır ve onu dizinin sonuna koyar.
  *
  * @param a döndürülecek yığın
  * @param c yığını döndürme sayısı
  */
void	ft_ra(t_stack *a, int c)
{
	int	i;
	int	count;
	int	temp;

	while (c--)
	{
		i = a->size;
		count = 0;
		temp = a->array[0];
		if (a->size > 1)
		{
			while (i-- > 1)
			{
				a->array[count] = a->array[count + 1];
				count++;
			}
			a->array[count] = temp;
			ft_printf("ra\n");
		}
	}
}
