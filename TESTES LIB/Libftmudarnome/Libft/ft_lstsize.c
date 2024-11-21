/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:27:50 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/22 14:54:12 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

//  int main(void) {
//     char str[] = "Hello, world!";
//     char str1[] = "Bye, world!";
//     //int i = 5;
//     //int *p;

//     //p = &i;
//     //printf("%p\n", p);
//     //printf("%d\n", *p);
//     t_list *teste;
//     t_list *teste1;
//     teste = ft_lstnew(str);
//     teste1 = ft_lstnew(str1);

//     printf("%s\n", (char *)(*teste).content);

//     ft_lstadd_front(&teste, teste1);

//     printf("%s\n", (char *)(*teste).content);

//     printf("%i", ft_lstsize(teste));

// }
