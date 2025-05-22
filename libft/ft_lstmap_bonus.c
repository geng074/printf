/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:02:55 by giho              #+#    #+#             */
/*   Updated: 2025/05/21 13:21:08 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	output = NULL;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&output, del);
			return (NULL);
		}
		new -> content = f(lst->content);
		new -> next = NULL;
		ft_lstadd_back(&output, new);
		lst = lst -> next;
	}
	return (output);
}
