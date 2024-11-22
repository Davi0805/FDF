/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:30:09 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/24 14:46:18 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

//Puxa o tamanho para ler string ao contrario para encontrar

char	*ft_strrchr(const char *s, int c)
{
	const char	*resultado;

	resultado = NULL;
	while (*s)
	{
		if (*s == (char)c)
			resultado = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)resultado);
}

// int main(void) {
//     printf("%s\n", ft_strrchr("teste", 's'));
//     printf("%s\n", strrchr("teste", 's'));
// }
