/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:52:11 by giho              #+#    #+#             */
/*   Updated: 2025/05/26 16:13:24 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_d(va_list args)
{
	int		num;
	int		len;
	char	*output;

	num = va_arg(args, int);
	output = ft_itoa(num);
	ft_putstr_fd(output, 1);
	len = ft_strlen(output);
	free(output);
	return (len);
}

int	ft_arg_u(va_list args)
{
	unsigned int	n;
	int				len;
	char			*output;

	n = va_arg(args, unsigned int);
	output = ft_uitoa(n);
	ft_putstr_fd(output, 1);
	len = ft_strlen(output);
	free(output);
	return (len);
}

int	ft_arg_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
