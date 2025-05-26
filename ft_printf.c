/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:09:52 by giho              #+#    #+#             */
/*   Updated: 2025/05/26 16:09:43 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_process(char *delimit_str, va_list args)
{
	char	arg_type;
	int		count;

	count = 0;
	arg_type = *(delimit_str + 1);
	if (arg_type == 'c')
		count = ft_arg_c(args);
	if (arg_type == '%')
		count = ft_arg_percent();
	if (arg_type == 's')
		count = ft_arg_s(args);
	if (arg_type == 'x')
		count = ft_arg_x(args);
	if (arg_type == 'X')
		count = ft_arg_x2(args);
	if (arg_type == 'p')
		count = ft_arg_p(args);
	if (arg_type == 'd' || arg_type == 'i')
		count = ft_arg_d(args);
	if (arg_type == 'u')
		count = ft_arg_u(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*output;
	char	*input;
	char	*delimit_str;
	int		count;

	count = 0;
	va_start(args, format);
	input = (char *)format;
	delimit_str = "";
	while (delimit_str)
	{
		delimit_str = ft_strchr(input, '%');
		output = ft_substr(input, 0, (size_t)(delimit_str - input));
		count = count + ft_strlen(output);
		ft_putstr_fd(output, 1);
		free(output);
		if (!delimit_str)
			return (count);
		count = count + ft_arg_process(delimit_str, args);
		input = delimit_str + 2;
	}
	va_end(args);
	return (count);
}
