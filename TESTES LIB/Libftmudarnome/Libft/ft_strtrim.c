/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:51:49 by davi              #+#    #+#             */
/*   Updated: 2024/04/24 14:03:32 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	testchar(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*stringvazia(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "", 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*resultado;
	int		inicioidx;
	int		fimidx;

	if (!s1 || !set)
		return (NULL);
	inicioidx = 0;
	while (testchar(s1[inicioidx], set))
		inicioidx++;
	fimidx = ft_strlen(s1) - 1;
	if (inicioidx == (int)ft_strlen(s1))
		return (stringvazia());
	while (testchar(s1[fimidx], set))
		fimidx--;
	resultado = (char *)malloc((fimidx - inicioidx + 2) * sizeof(char));
	if (!resultado)
		return (NULL);
	ft_strlcpy(resultado, (s1 + inicioidx), (fimidx - inicioidx + 2));
	return (resultado);
}
//int main(void) {
// 	char s1[] = "eeetelorem ipsum dolor sit ametttee";
//
//    printf("Resultado: %s\n", ft_strtrim(s1, "te"));
//
//     return 0;
//}
