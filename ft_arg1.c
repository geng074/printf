/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:49:37 by giho              #+#    #+#             */
/*   Updated: 2025/05/26 16:13:08 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_c(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putchar_fd((char)num, 1);
	return (1);
}

int	ft_arg_s(va_list args)
{
	char	*output;

	output = va_arg(args, char *);
	if (!output)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(output, 1);
	return (ft_strlen(output));
}

int	ft_arg_x(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_hex(n, 0));
}

int	ft_arg_x2(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_hex(n, 1));
}

int	ft_arg_p(va_list args)
{
	uintptr_t	ptr_hex;

	ptr_hex = (uintptr_t)va_arg(args, void *);
	if (ptr_hex == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (2 + ft_putnbr_ptrhex(ptr_hex, 0));
}
