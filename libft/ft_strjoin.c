/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:48:00 by giho              #+#    #+#             */
/*   Updated: 2025/05/14 20:14:34 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len +1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		*str = *s1;
		s1++;
		str++;
	}
	while (*s2 != '\0')
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = '\0';
	return (str - len);
}
