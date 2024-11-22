/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:37:53 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/24 17:49:33 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ptr;
	size_t	dstlen;
	size_t	srclen;
	size_t	resultado;
	size_t	i;

	ptr = (char *)src;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	resultado = 0;
	i = 0;
	if (size > dstlen)
		resultado = srclen + dstlen;
	else
		resultado = srclen + size;
	while (ptr[i] && (dstlen + 1) < size)
	{
		dst[dstlen] = ptr[i];
		dstlen++;
		i++;
	}
	if (dstlen < size)
		dst[dstlen] = '\0';
	return (resultado);
}
