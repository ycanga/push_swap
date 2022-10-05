/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:34:32 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/28 19:34:33 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdlib.h>
# include "colors.h"

int		ft_printf(const char *key, ...);

int		arg_printer(char c, va_list macro);

int		ft_putstr(char *c);

int		ft_putpointer(unsigned long int point);

int		ft_puthex(unsigned int point, char *charset);

int		ft_putnbr(int nb);

int		ft_putunsigned(unsigned long nb);

#endif
