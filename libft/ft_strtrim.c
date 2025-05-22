/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:20:51 by giho              #+#    #+#             */
/*   Updated: 2025/05/21 14:11:09 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_chrset(const char s, const char *set)
{
	while (*set != '\0')
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	s1_len;
	size_t	end;
	size_t	len;

	i = 0;
	while ((ft_is_chrset(s1[i], set)) && *s1 != '\0')
		i++;
	start = i;
	s1_len = ft_strlen(s1);
	i = s1_len - 1;
	while ((ft_is_chrset(s1[i], set)) && i > start)
		i--;
	end = i;
	len = end - start + 1;
	if (len <= 0)
		return (ft_empty_string());
	else
		return (ft_substr(s1, start, len));
}
