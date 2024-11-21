/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:22 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/24 12:08:03 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*resultado;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	resultado = ft_calloc((len + 1), sizeof(char));
	if (resultado == NULL)
		return (NULL);
	while (i < len)
	{
		resultado[i] = s[start + i];
		i++;
	}
	return (resultado);
}
/*int main(void) {

    printf("Resultado: %s", ft_substr("", 0, 0));

    return 0;
}*/
