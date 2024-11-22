/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:05:47 by davi              #+#    #+#             */
/*   Updated: 2024/04/22 14:48:19 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_dest;
	char	*p_src;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	p_src = (char *)src;
	p_dest = (char *)dest;
	i = 0;
	if (p_dest > p_src)
	{
		while (n-- > 0)
			p_dest[n] = p_src[n];
	}
	else
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}
