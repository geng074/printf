/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:52:21 by giho              #+#    #+#             */
/*   Updated: 2025/05/22 15:24:11 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_start;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_start = (size_t)start;
	if (sub_start > s_len)
		return (ft_empty_string());
	if (len > s_len - sub_start)
		len = s_len - sub_start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while ((i < len) && s[i + sub_start] != '\0')
	{
		substr[i] = s[i + sub_start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
