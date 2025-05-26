/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:10:10 by giho              #+#    #+#             */
/*   Updated: 2025/05/26 16:10:46 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
//# include <stdio.h>

int		ft_printf(const char *format, ...);
char	*ft_uitoa(unsigned int n);
int		ft_putnbr_ptrhex(uintptr_t n, int i);
int		ft_putnbr_hex(unsigned int n, int i);
int		ft_arg_c(va_list args);
int		ft_arg_s(va_list args);
int		ft_arg_x(va_list args);
int		ft_arg_x2(va_list args);
int		ft_arg_p(va_list args);
int		ft_arg_d(va_list args);
int		ft_arg_u(va_list args);
int		ft_arg_percent(void);

#endif