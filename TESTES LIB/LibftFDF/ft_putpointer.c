/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:38:06 by davi              #+#    #+#             */
/*   Updated: 2024/05/02 12:07:31 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "ft_printf.h"

void	reverseprint(int i, char *buffer)
{
	int	j;

	j = i - 1;
	write(1, "0x", 2);
	while (j >= 0)
	{
		write(1, &buffer[j], 1);
		j--;
	}
}

int	exception(void)
{
	write(1, "(nil)", 5);
	return (5);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	address;
	char			buffer[20];
	int				numchar;
	int				i;
	int				digit;

	i = 0;
	address = (unsigned long)ptr;
	if (address == 0)
		return (exception());
	while (address > 0)
	{
		digit = address % 16;
		if (digit < 10)
			buffer[i] = digit + '0';
		else
			buffer[i] = digit - 10 + 'a';
		address /= 16;
		i++;
	}
	numchar = i + 2;
	reverseprint(i, buffer);
	return (numchar);
}

// int	main(void)
// {
// 	char	*ptr;

// 	ptr = (char *)malloc(20 * sizeof(char));
// 	putpointer(ptr);
// }
