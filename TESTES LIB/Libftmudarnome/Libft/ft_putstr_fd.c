/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:06:06 by davi              #+#    #+#             */
/*   Updated: 2024/04/21 17:19:41 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
int main()
{
	char str[] = "O rato roeu a roupa do rei de roma";

	ft_putstr_fd(str, open("putstrteste.txt", O_RDWR | O_CREAT));

	return 0;
}
*/
