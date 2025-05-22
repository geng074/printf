/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:54:02 by giho              #+#    #+#             */
/*   Updated: 2025/05/13 15:16:09 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	char buffer[11];
// 	printf("hi is");
// 	ft_memset(buffer, 'A', 10);
// 	buffer[10] ='\0';
// 	printf(	"test is %s\n",buffer);
// 	ft_bzero(buffer, 5);
// 	printf(	"test is a%s\n",buffer);

// }