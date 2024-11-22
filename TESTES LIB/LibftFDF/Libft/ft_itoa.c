/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:15:42 by davi              #+#    #+#             */
/*   Updated: 2024/04/22 15:06:23 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Lembrete: integer nao existe numero quebrado.
 Ex: "0.245". Apenas em float*/
/*Logo, quando for dividindo por 10 o while para
 quando chegar em numero quebrado*/

int	numcount(long n)
{
	int	contador;

	contador = 0;
	if (n < 0)
	{
		n = -n;
		contador++;
	}
	if (n == 0)
		contador++;
	while (n != 0)
	{
		n /= 10;
		contador++;
	}
	return (contador);
}

char	*alocamemoria(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	*resultado;
	int		i;
	long	nbr;
	int		digitos;

	nbr = n;
	digitos = numcount(nbr);
	resultado = alocamemoria(digitos);
	if (!resultado)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = digitos - 1;
	while (nbr != 0)
	{
		resultado[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		resultado[0] = '-';
	resultado[digitos] = 0;
	return (resultado);
}

//  int main() {
// 	int num = -155;
// 	char *str = ft_itoa(num);

// 	printf("%s\n", str);

// 	free(str);

// 	return 0;
// }
