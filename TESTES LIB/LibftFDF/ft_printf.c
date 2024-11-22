/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:17:34 by davi              #+#    #+#             */
/*   Updated: 2024/05/07 14:49:47 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./Libft/libft.h"
#include "ft_printf.h"

int	flagchecker(char *flags, char c)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	printputstr(va_list ap, const char *format, int i)
{
	if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'p')
		return (ft_putpointer(va_arg(ap, void *)));
	else if (format[i + 1] == 'd')
		return (ft_putint(va_arg(ap, int)));
	else if (format[i + 1] == 'i')
		return (ft_putint(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_putunsint(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x')
		return (ft_puthexlowcase(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'X')
		return (ft_puthexupcase(va_arg(ap, unsigned int)));
	else if (format[i + 1] == '%')
		return (ft_putpercent());
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		numchar;
	int		i;

	numchar = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && flagchecker("cspdiuxX%", format[i + 1]) == 1)
		{
			numchar += printputstr(ap, format, i);
			i++;
		}
		else
			numchar += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (numchar);
}

/*// int	main(void)
// {
// 	char letra;
// 	char nome[20];
// 	int	idade;
// 	int ano;
// 	nome[0] = 'D';
// 	nome[1] = 'a';
// 	nome[2] = 'v';
// 	nome[3] = 'i';
// 	nome[4] = '\0';
// 	idade = 20;
// 	ano = 2004;
// 	letra = 'D';
// //ft_putpointer(nome);
// //ft_printf("%X", ano);
// 	ft_printf("Eu sou %s.", nome);
// 	printf("Eu sou %s.", nome)

// 	return 0;
// }*/
