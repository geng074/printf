/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:09:08 by giho              #+#    #+#             */
/*   Updated: 2025/05/26 16:11:09 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//int 	num;
//	int num2 = -223;
//	int x = 'd';
	//num = -3.21;
//	unsigned int	hex = 1234;	
	
//	unsigned int	n = 12;
//	char *ptr = "bbbb";
//	char *str = "finish";
//	printf("hello world %u\n ", n);
	//ft_printf("hello world %i", num2);

//	printf("hello world %% %% %u\n ", n);
//	printf("hello world %x\n ",hex);

///	ft_printf("hello world %% %X\n ",hex);

//	ft_printf("hello world %c\n ",x);

///	ft_printf("hello world %u\n ",n);
	//printf("\ncount is %d\n",ft_printf("hello world %% afn"));
	
//	ft_printf("hello world \" %% test %p %d",ptr,num2);


//	printf("\ncount is %d\n",ft_printf("hello world \" %% test %c %p %d %s",x, ptr,num2, str));

//	printf("\ncount is %d\n",ft_printf("hello world \" %% test %c %d %s %p",x, num2, str, ptr));

	//char *ptr = -1;
	printf("\ncount is %d\n",printf("%p", (void *)0));
	printf("\ncount is %d\n",ft_printf("%p", (void*)0));


	//TEST(1, print(" %p ", -1));

}

