/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:09:52 by giho              #+#    #+#             */
/*   Updated: 2025/05/22 17:54:46 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>


void ft_putnbr_ptrhex(uintptr_t n, int i)
{
	char *hex;
	if (i == 0)
		hex = ft_strdup("0123456789abcdef");
	else
		hex = ft_strdup("0123456789ABCDEF");
	
	if (n >= 16)
		ft_putnbr_ptrhex(n / 16, i);
	write(1, &hex[n % 16],1);
}


void ft_putnbr_hex(unsigned int n, int i)
{
	char *hex;
	if (i == 0)
		hex = ft_strdup("0123456789abcdef");
	else
		hex = ft_strdup("0123456789ABCDEF");
	
	if (n >= 16)
		ft_putnbr_hex(n / 16, i);
	write(1, &hex[n % 16],1);
}

//printf("test is %d", num);
int ft_printf(const char *format, ...)
{
	va_list	args;
	char	*output;
	char	*delimit_str;
	char	arg_type;
	//int		count;
	int num;
	uintptr_t ptr_hex;
	unsigned int	n;
	
	//char	x;
	//size_t	len;

	va_start(args, format);
	printf("string: %s\n",format);

	
	delimit_str = ft_strchr(format, '%');
	
	output = ft_substr(format, 0, (size_t)(delimit_str - format));

	// printf("output: %s\n",output);
	ft_putstr_fd(output, 1);

	// printf("after: %s\n",delimit_str);

	arg_type = *(delimit_str+1);
	// printf("arg type: %c\n",arg_type);

	if (arg_type == 'c')
	{
		num = va_arg(args, int);
		ft_putchar_fd((char)num, 1);
	}

	if (arg_type == '%')
	{
		ft_putchar_fd('%', 1);
		delimit_str++;
	}
	
	if (arg_type == 's')
	{
		output = va_arg(args, char *);
		ft_putstr_fd(output, 1);
	}

	if (arg_type == 'x')
	{
		n = va_arg(args, unsigned int);
		ft_putnbr_hex(n, 0);
	}
	
	if (arg_type == 'X')
	{
		n = va_arg(args, unsigned int);
		ft_putnbr_hex(n, 1);
	}
	
	if (arg_type == 'p')
	{
		ptr_hex = (uintptr_t)va_arg(args, void *);
		ft_putstr_fd("0x", 1);
		ft_putnbr_ptrhex(ptr_hex, 1);
	}

	if (arg_type == 'd' || arg_type == 'i')
	{	
		num = va_arg(args, int);
		output = ft_itoa(num);
		ft_putstr_fd(output, 1);
		// printf("%s\n",output);
	}
	
	if (arg_type == 'u')
	{	
		n = va_arg(args,unsigned int);
		output = ft_uitoa(n);
		ft_putstr_fd(output, 1);
		// printf("%s\n",output);
	}

	
	// num = va_arg(args, int);
	// printf("test2 is %d\n",num);
	
	va_end(args);
	return (0);
}