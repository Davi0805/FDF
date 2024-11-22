/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:16:58 by davi              #+#    #+#             */
/*   Updated: 2024/04/21 17:37:19 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*
int main()
{
	char str[] = "O rato roeu a roupa do rei de roma";

	ft_putendl_fd(str, open("putendlteste.txt", O_RDWR | O_CREAT));

	return 0;
}
*/
