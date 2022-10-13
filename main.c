/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:36:22 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/12 21:57:22 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
  * Yığınları başlatır, girişi kontrol eder, girişin sıralanıp sıralanmadığını kontrol eder ve yığınları serbest bırakır
  *
  * @param argc programa iletilen argümanların sayısı
  * @param argv programa iletilen dizi dizisi
  *
  * @return Program 0 döndürüyor.
  */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*p;

	if (argc < 1)
		exit (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	p = malloc(sizeof(char));
	init(a, b, &p, argv);
	ft_check(p, a, b);
	ft_check_sort(a, b);
	ft_free(a, b);
	free(p);
	return (0);
}
