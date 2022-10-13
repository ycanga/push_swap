/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:12:26 by ycanga            #+#    #+#             */
/*   Updated: 2022/10/13 13:12:19 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*array;
	int	size;
	int	*start;
}				t_stack;

void	init(t_stack *a, t_stack *b, char **p, char **argv);
void	ft_split_stacks(char *str, t_stack *a, t_stack *b);
void	ft_check_repeat(t_stack *a, t_stack *b);
void	ft_check_sort(t_stack *a, t_stack *b);
void	ft_check_symbols(char *str, t_stack *a, t_stack *b);
void	ft_check(char *str, t_stack *a, t_stack *b);
void	ft_error(t_stack *a, t_stack *b, int err);
void	ft_check_sort(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_swap_trois(t_stack *a);
void	ft_rra(t_stack *a, int c);
int		ft_check_sorted(t_stack *a);
void	ft_swap_quatre(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b, int c);
void	ft_pa(t_stack *a, t_stack *b, int c);
void	ft_ra(t_stack *a, int c);
void	ft_swap_cinq(t_stack *a, t_stack *b);
void	ft_rrb(t_stack *b);
void	ft_rb(t_stack *b);
void	ft_index(t_stack *a);
void	ft_send_to_sup(t_stack *a, t_stack *b, int *p);
void	ft_sort_plus(t_stack *a, t_stack *b);
void	ft_make_index(t_stack *a, int *tab);
void	ft_push_b(t_stack *a, t_stack *b);
void	ft_push_a(t_stack *a, t_stack *b);
void	ft_pre_a(t_stack*a, t_stack *b);
void	ft_helper(t_stack *a, t_stack *b);
void	ft_free(t_stack *a, t_stack *b);
char	*ft_strjoin_ps(char *s1, char *s2);
int		ft_pre_b(t_stack *b, int *p);
int		ft_floor(t_stack *a, int x, int len);
int		*ft_sort_index(t_stack *a);
int		ft_pivot(t_stack *a);
int		ft_min(int *p, int len);
int		*ft_calc(t_stack *a, t_stack *b);
int		ft_min(int *p, int len);
#endif
