/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:58:04 by csil              #+#    #+#             */
/*   Updated: 2023/10/16 13:01:08 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// Main function 
char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = recup(stock, fd);
	if (!stock)
		return (NULL);
	line = create_line(stock);
	stock = clean_stock(stock);
	return (line);
}

// Create the stock line
char	*recup(char *stock, int fd)
{
	char	*str;
	int		count;

	if (!stock)
		stock = (char *)ft_calloc(1, sizeof(char));
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str || !stock)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count == -1)
		{
			free(str);
			free(stock);
			return (NULL);
		}
		str[count] = '\0';
		stock = ft_strjoin(stock, str);
		if (found_n(str) != -1)
			break ;
	}
	free(str);
	return (stock);
}

// Create the line to return
char	*create_line(char *stock)
{
	int		i;
	char	*str;

	if (!stock[0])
		return (NULL);
	i = found_n(stock);
	if (i == -1)
		i = ft_strlen(stock);
	str = ft_strndup(stock, i);
	if (!str)
		return (NULL);
	return (str);
}

// Clean the stock
char	*clean_stock(char *stock)
{
	int		i;
	int		j;
	char	*str;

	if (!stock)
		return (free_all(stock));
	i = found_n(stock);
	if (i == -1)
		return (free_all(stock));
	str = malloc(sizeof(char) * (ft_strlen(stock + i) + 1));
	if (!str)
		return (free_all(stock));
	i++;
	j = 0;
	while (stock[i])
	{
		str[j++] = stock[i++];
	}
	str[j] = '\0';
	free(stock);
	return (str);
}

// Free the stock
char	*free_all(char *stock)
{
	free(stock);
	return (NULL);
}

// Make it work
/*int	main(void)
{
	int		fd = 0;
	char	*str = NULL;

	fd = open("test.txt", 'r');
	if (!fd)
		return (0);
	while (1)
	{
		str = get_next_line(fd);
		printf ("%s", str);
		if (!str)
		{
			free(str);
			close(fd);
			return (0);
		}
		free(str);
	}
	close(fd);
	return (0);
}*/
