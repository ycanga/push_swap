/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:11:49 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/13 10:00:16 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * Girdi dizisinde geçersiz semboller olup olmadığını kontrol eder.
  *
  * @param str kontrol edilecek sayı dizisi
  * @param ilk yığına bir işaretçi
  * @param b yığını b
  */
void	ft_check_symbols(char *str, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && \
		(str[i + 1] == '-' || str[i + 1] == '+'))
			ft_error(a, b, 0);
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == '-' || \
		str[i + 1] == '+'))
			ft_error(a, b, 1);
		i++;
	}
	ft_split_stacks(str, a, b);
}

/**
  * Hatalar için girişi kontrol eder
  *
  * @param str kontrol edilecek dize
  * @param ilk yığına bir işaretçi
  * @param b yığını b
  */
void	ft_check(char *str, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (!str)
		ft_error(a, b, 3);
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == ' ') || \
		str[i] == '-' || str[i] == '+'))
			ft_error(a, b, 1);
		i++;
	}
	ft_check_symbols(str, a, b);
}

/**
  * Yığında tekrarlanan sayı olup olmadığını kontrol eder
  *
  * @param ilk yığına bir işaretçi
  * @param b sıralanmayan yığın
  */
void	ft_check_repeat(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < a->size)
	{
		while (j < a->size)
		{
			if (a->array[j] == a->array[i])
				ft_error(a, b, 2);
			j++;
		}
		i++;
		j = 1 + i;
	}
}

/**
  * Yığının sıralanıp sıralanmadığını kontrol eder, öyle ise sıralar.
  *
  * @param a ilk yığın
  * @param b yığını sıralamak için kullanılacak yığın a.
  */
void	ft_check_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		if (a->array[0] > a->array[1])
			ft_sa(a);
	if (a->size == 3)
		if (ft_check_sorted(a))
			ft_swap_trois(a);
	if (a->size == 4)
		if (ft_check_sorted(a))
			ft_swap_quatre(a, b);
	if (a->size == 5)
	{
		if (ft_check_sorted(a))
			ft_swap_cinq(a, b);
	}
	if (a->size > 5)
		if (ft_check_sorted(a))
			ft_sort_plus(a, b);
}

/**
  * Yığının sıralanıp sıralanmadığını kontrol eder
  *
  * @param a Kontrol edilecek yığın
  *
  * @return 1 yığın sıralanmamışsa, 0 ise.
  */
int	ft_check_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if ((i + 1 != a->size) && a->array[i] > a->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}
