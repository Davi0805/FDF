/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:25:50 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/23 14:53:25 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*resultado;

	i = 0;
	resultado = (unsigned char *)s;
	while (i < n)
	{
		if (resultado[i] == (unsigned char)c)
			return (&resultado[i]);
		i++;
	}
	return (NULL);
}
