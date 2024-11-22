/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:07:20 by davi              #+#    #+#             */
/*   Updated: 2024/09/27 14:27:28 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*ft_get_substr(char const *s, unsigned int start, size_t len);
char	*ft_get_strdup(const char *s);
char	*ft_get_strchr(char *str, int c);
char	*ft_get_strjoin(char *s1, char *s2);
size_t	ft_get_strlen(const char *s);
char	*get_next_line(int fd);

#endif
