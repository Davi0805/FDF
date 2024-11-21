/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:53:48 by davi              #+#    #+#             */
/*   Updated: 2024/11/18 23:05:34 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Contar quantos espacos sao necessarios no ponteiro
size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	contador;

	i = 0;
	contador = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			contador++;
			while (str[i] && str[i] != c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (contador);
}

size_t	wordsize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	memfree(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

char	**split(char const *s, char c, char **array, size_t count_words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < count_words)
	{
		while (s[j] && s[j] == c)
			j++;
		array[i] = ft_substr(s, j, wordsize(&*(s + j), c));
		if (!array[i])
		{
			memfree(i, array);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	nwords;

	if (!s)
		return (NULL);
	nwords = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, nwords);
	return (array);
}

// int main(void) {
//     char str[] = {"davi,marcos,hugo"};
// 	char **teste = ft_split(str, ',');

//     printf("%s\n", teste[3]);

// 	return 0;
// }
