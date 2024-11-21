/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:45:35 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/05/01 10:47:52 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "ft_printf.h"

int	ft_putint(int n)
{
	char	*p;
	size_t	len;

	p = ft_itoa(n);
	len = ft_strlen(p);
	write(1, p, len);
	free(p);
	return (len);
}
