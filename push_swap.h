/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:58:57 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/05 16:22:37 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"

typedef struct s_stack
{
	void	**stack_a;
	void	**stack_b;
	int		digit_a;
}t_stack;

void	check_arg(int argc, char **argv, t_stack *t_data);
void	ft_error(char *str, int is_true, t_stack *t_data);

#endif