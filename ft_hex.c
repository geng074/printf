/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:45:59 by giho              #+#    #+#             */
/*   Updated: 2025/05/26 16:12:26 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ptrhex(uintptr_t n, int i)
{
	char	*hex;
	int		count;

	count = 1;
	if (i == 0)
		hex = ft_strdup("0123456789abcdef");
	else
		hex = ft_strdup("0123456789ABCDEF");
	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	if (n >= 16)
		count = count + ft_putnbr_ptrhex(n / 16, i);
	write(1, &hex[n % 16], 1);
	free(hex);
	return (count);
}

int	ft_putnbr_hex(unsigned int n, int i)
{
	char	*hex;
	int		count;

	count = 1;
	if (i == 0)
		hex = ft_strdup("0123456789abcdef");
	else
		hex = ft_strdup("0123456789ABCDEF");
	if (n >= 16)
		count = count + ft_putnbr_hex(n / 16, i);
	write(1, &hex[n % 16], 1);
	free(hex);
	return (count);
}
