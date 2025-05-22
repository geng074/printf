/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:09:08 by giho              #+#    #+#             */
/*   Updated: 2025/05/22 17:57:00 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int main()
{
	//int 	num;
	//int num2 = 2;
	//int x = 'd';
	//num = -3.21;
	
	unsigned int	n = -123;
	//char *ptr = "bbbb";
	printf("hello world %u\n ", n);
//	printf("hello world %u\n ", num);
	ft_printf("hello world %u\n ",n);


//	ft_printf("hello world %p\n %d",ptr);
}