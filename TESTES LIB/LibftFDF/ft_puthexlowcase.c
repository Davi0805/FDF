/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlowcase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:26:26 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/05/06 10:54:43 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "ft_printf.h"

int	digitosl(unsigned long n)
{
	int	nsize;

	nsize = 0;
	while (n != 0)
	{
		n /= 16;
		nsize++;
	}
	return (nsize);
}

char	*inttohexl(unsigned long n, int nsize)
{
	char	*res;
	int		tempn;
	int		i;

	i = 0;
	res = (char *)malloc((nsize + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (n != 0)
	{
		tempn = n % 16;
		if (tempn < 10)
			res[i++] = tempn + '0';
		else
			res[i++] = tempn + 87;
		n /= 16;
	}
	res[i] = '\0';
	return (res);
}

int	exceptionxl(void)
{
	write(1, "0", 1);
	return (1);
}

int	ft_puthexlowcase(unsigned long n)
{
	char	*result;
	int		nsize;
	int		i;
	char	tempchar;

	if (n == 0)
		return (exceptionxl());
	nsize = digitosl(n);
	result = inttohexl(n, nsize);
	i = nsize - 1;
	while (i >= 0)
	{
		write(1, &result[i], 1);
		i--;
	}
	free(result);
	return (nsize);
}

/*int	main(void)
{
	int	n = 64531;

	ft_puthexupcase(n);
}*/
