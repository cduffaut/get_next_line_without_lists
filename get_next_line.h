/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:59:19 by csil              #+#    #+#             */
/*   Updated: 2023/10/16 19:27:43 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*create_stock(char *stock, int fd);
char	*create_line(char *stock);
char	*clean_stock(char *stock);
char	*free_all(char *str);
int		check_n(char *str);
char	*ft_strjoin(char *stock, char *tmp);
int		ft_strlen(char *str);
char	*ft_strndup(char *stock, int i);
void	*ft_calloc(size_t nb_elem, size_t size_elem);

#endif
