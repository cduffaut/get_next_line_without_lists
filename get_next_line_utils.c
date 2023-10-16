/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:58:51 by csil              #+#    #+#             */
/*   Updated: 2023/10/16 12:53:07 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Malloc a ptr and fill it with \0
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}

// Chec if there is an \n (return index) or not (return -1)
int	found_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// Malloc and concatenate str one and two and return it
char	*ft_strjoin(char *one, char *two)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(one) + ft_strlen(two) + 1));
	if (!str)
	{
		free(one);
		return (NULL);
	}
	i = 0;
	while (one[i])
	{
		str[i] = one[i];
		i++;
	}
	j = 0;
	while (two[j])
		str[i++] = two[j++];
	str[i] = '\0';
	free(one);
	return (str);
}

// Return the len of the str
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// Duplicate stock until index and return it
char	*ft_strndup(char *stock, int i)
{
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	j = 0;
	while (j <= i && stock[j])
	{
		str[j] = stock[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
