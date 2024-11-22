/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:41:09 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/22 14:11:22 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	caracter;

	i = 0;
	caracter = (char) c;
	while (str[i])
	{
		if (str[i] == caracter)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == caracter)
		return ((char *) &str[i]);
	return (NULL);
}

//  int main(void) {
//      printf("%s", ft_strchr("teste", 'a'));
//      printf("%s", ft_strchr("teste", 'a'));
// }
