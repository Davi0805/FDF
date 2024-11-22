/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:28:00 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/22 13:39:39 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*resultado;

	i = 0;
	j = 0;
	resultado = (char *)malloc(
			(ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (resultado == NULL)
		return (NULL);
	while (s1[i])
		resultado[j++] = s1[i++];
	i = 0;
	while (s2[i])
		resultado[j++] = s2[i++];
	resultado[j] = '\0';
	return (resultado);
}
/* int main () {
    char s1[] = {"one"};
    char s2[] = {"two"};
    //char str = ft_strjoin(s1, s2);

    printf("String after |%s|\n", ft_strjoin(s1, s2));

    return 0;
} */
