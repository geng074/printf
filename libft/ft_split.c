/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giho <giho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:44:50 by giho              #+#    #+#             */
/*   Updated: 2025/05/20 19:05:51 by giho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	ft_count_word(char const *s, char c)
{
	size_t	word_count;
	size_t	in_word;

	if (!s)
		return (0);
	word_count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			word_count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (word_count);
}

static void	ft_free(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_split_helper2(char **arr, char const *curr,
	char const *nextstr, int *i)
{
	if (!nextstr)
	{
		arr[(*i)++] = ft_substr(curr, 0, (size_t)ft_strlen(curr));
		if (arr[*i - 1] == NULL)
			return (ft_free(arr), -1);
		return (0);
	}
	if (nextstr - curr > 0)
	{
		arr[(*i)++] = ft_substr(curr, 0, (size_t)(nextstr - curr));
		if (arr[*i - 1] == NULL)
			return (ft_free(arr), -1);
	}
	return (1);
}

static int	ft_split_helper(char **arr, char const *s, char c)
{
	const char	*curr;
	const char	*nextstr;
	int			i;
	int			result;

	curr = s;
	i = 0;
	while (*curr)
	{
		nextstr = ft_strchr(curr, (int)c);
		result = ft_split_helper2(arr, curr, nextstr, &i);
		if (result == -1)
			return (-1);
		if (result == 0)
			break ;
		if (*nextstr == '\0')
			break ;
		curr = nextstr + 1;
	}
	arr[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_word(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (ft_split_helper(arr, s, c) == -1)
		return (NULL);
	return (arr);
}
