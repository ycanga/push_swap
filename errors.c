/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:12:03 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 22:12:04 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * Hataları kontrol eder ve varsa yığınları serbest bırakır.
  *
  * @param a İlk yığın
  * @param b Sıralanmayan yığın.
  * @param err 0 = geçersiz komut, 1 = geçersiz sayı, 2 = geçersiz sayı, 3 = geçersiz sayı
  */
void	ft_error(t_stack *a, t_stack *b, int err)
{
	(void)a;
	(void)b;
	if (err == 0)
		write(2, "Error\n", 6);
	if (err == 1)
		write(2, "Error\n", 6);
	if (err == 2)
		write(2, "Error\n", 6);
	if (err == 3)
		write(2, "Error\n", 6);
	ft_free(a, b);
}
