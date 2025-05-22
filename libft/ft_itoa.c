/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:11:51 by giho              #+#    #+#             */
/*   Updated: 2025/05/21 10:27:52 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_helper(char *temp, int negative, int i)
{
	int		len;
	char	*str;

	len = ft_strlen(temp);
	str = (char *)malloc((negative + len + 1));
	if (!str)
		return (free(temp), NULL);
	i = 0;
	if (negative == 1)
		str[0] = '-';
	while (i < len)
	{
		str[i + negative] = temp[len - 1 - i];
		i++;
	}
	str[i + negative] = '\0';
	free(temp);
	return (str);
}

static char	*ft_itoa_temp(int n, int *i)
{
	char	*temp;
	int		digit;

	temp = (char *)malloc(10 + 1);
	if (!temp)
		return (NULL);
	if (n == 0)
		temp[(*i)++] = '0';
	while (n > 0)
	{
		digit = n % 10;
		temp[(*i)++] = digit + '0';
		n = n / 10;
	}
	temp[*i] = '\0';
	return (temp);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*temp;
	int		i;
	int		negative;

	i = 0;
	negative = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str = ft_strdup("-2147483648");
			return (str);
		}
		n = -n;
		negative = 1;
	}
	temp = ft_itoa_temp(n, &i);
	str = ft_itoa_helper(temp, negative, i);
	return (str);
}
