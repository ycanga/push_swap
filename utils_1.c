/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:31:06 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/03 16:19:05 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int argc, char **argv, t_stack *t_data)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		ft_printf("%s", tab[3]);
		// if (ft_atoi(tab[j]) == 0 && tab[j][0] != '0')
		// 	ft_error("Dont use letters or special characters", 0, t_data);
		t_data->a = 0;
		j = 0;
		while (tab[j])
		{
			ft_printf("%d", j);
			// if(ft_strlcpy(t_data->stack_a[j], tab[j], ft_strlen(tab[j])))
			// 	ft_printf("OK");
			// else
			// 	ft_error("Error", 0, t_data);
			j++;
		}
		i++;
	}
}