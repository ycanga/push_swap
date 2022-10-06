/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:31:06 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/05 19:55:18 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int argc, char **argv, t_stack *t_data)
{
	int		i;
	int		j;
	int		a;
	int		count;
	char	**tab;
	int		nums[20];
	int		digit_a;

	i = 1;
	a = 0;
	count = ft_strlen(argv[i]);
	tab = ft_calloc(sizeof(count), 1);
	digit_a = t_data->digit_a;
	while (i < argc)
	{
		j = 0;
		tab = ft_split(argv[i], ' ');
		while (tab[j])
		{
			nums[a] = ft_atoi(tab[j]);
			j++;
			a++;
		}
		i++;
	}
	i = 0;
	while (i < 20)
	{
		ft_printf("%d\n", nums[i]);
		i++;
	}
}