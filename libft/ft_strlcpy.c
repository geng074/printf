/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:54:34 by giho              #+#    #+#             */
/*   Updated: 2025/05/13 15:31:33 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	while (src[i] != '\0')
		i++;
	srclen = i;
	if (size == 0)
		return (srclen);
	i = 0;
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// size_t ft_strlen(const char *s)
// {
// 	size_t i;
// 	i = 0;
// 	while (s[i]!='\0')
// 		i++;
// 	return (i);
// }
// int	main(void)
// {
// 	char *src =	"hello";
// 	char dest[20];
// 	printf("test is %zu\n", ft_strlcpy(dest, src, 3));
// 	printf("test is %s", dest);
// }
