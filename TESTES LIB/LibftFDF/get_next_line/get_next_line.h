/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:06:53 by davi              #+#    #+#             */
/*   Updated: 2024/10/01 17:49:46 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char	*ft_get_substr(char const *s, unsigned int start, size_t len);
char	*ft_get_strdup(const char *s);
char	*ft_get_strchr(char *str, int c);
char	*ft_get_strjoin(char *s1, char *s2);
size_t	ft_get_strlen(const char *s);
char	*get_next_line(int fd);

#endif
