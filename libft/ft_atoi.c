/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:43:58 by giho              #+#    #+#             */
/*   Updated: 2025/05/14 18:08:00 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	long	negative;

	negative = 1;
	result = 0;
	if (!nptr)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			negative = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + ((long)*nptr) - 48;
		nptr++;
	}
	return ((int)(result * negative));
}
