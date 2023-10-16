/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:56:29 by cduffaut          #+#    #+#             */
/*   Updated: 2023/10/16 19:33:52 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void			*ptr;
	size_t			i;
	unsigned char	c;

	ptr = malloc(nb_elem * size_elem);
	if (!ptr)
		return (NULL);
	i = 0;
	c = '\0';
	while (i < (nb_elem * size_elem))
	{
		((char *)ptr)[i] = c;
		i++;
	}
	return (ptr);
}

// Check if there is \n, return index if yes, -1 if no
int	check_n(char *str)
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

char	*ft_strjoin(char *stock, char *tmp)
{
	int		j;
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(stock) + ft_strlen(tmp) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	if (!str)
		free(stock);
	if (!str)
		return (NULL);
	i = 0;
	while (stock[i])
	{
		str[i] = stock[i];
		i++;
	}
	j = 0;
	while (tmp[j])
		str[i++] = tmp[j++];
	free(stock);
	str[i] = '\0';
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

char	*ft_strndup(char *stock, int i)
{
	int		j;
	char	*line;

	j = 0;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (j <= i && stock[j])
	{
		line[j] = stock[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
