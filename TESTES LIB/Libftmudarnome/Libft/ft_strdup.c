/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:56:40 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/22 13:23:00 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*resultado;

	len = 0;
	while (s[len])
		len++;
	resultado = (char *)malloc(len + 1);
	i = 0;
	if (resultado == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		resultado[i] = s[i];
		i++;
	}
	resultado[i] = '\0';
	return (resultado);
}
/*
int main()
{
    char source[] = "GeeksForGeeks";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = ft_strdup(source);

    printf("%s", target);
    return 0;
}*/
