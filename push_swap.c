/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:23:41 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/05 16:48:25 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*t_data;

	t_data = (t_stack *)ft_calloc(sizeof(t_stack), sizeof(t_data));
	if (argc > 1)
	{
		check_arg(argc, argv, t_data);
	}
}
