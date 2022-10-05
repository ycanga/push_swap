/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:12:15 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/03 14:35:57 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str, int is_true, t_stack *t_data)
{
	ft_printf("%s\n", str);
	free(t_data);
	if (is_true == 1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
