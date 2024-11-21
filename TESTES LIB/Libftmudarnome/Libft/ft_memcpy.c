/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:15:46 by davi              #+#    #+#             */
/*   Updated: 2024/04/23 12:34:32 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*c;

	p = (unsigned char *)dest;
	c = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (n > 0)
	{
		*p = *c;
		p++;
		c++;
		n--;
	}
	return (dest);
}
