/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:49:18 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/22 13:58:51 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst || new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*  int main(void) {
    char str[] = "Hello, world!";
    char str1[] = "Bye, world!";
    //int i = 5;
    //int *p;

    //p = &i;
    //printf("%p\n", p);
    //printf("%d\n", *p);
    t_list *teste;
    t_list *teste1;
    teste = ft_lstnew(str);
    teste1 = ft_lstnew(str1);

    printf("%s\n", (char *)(*teste).content);

    ft_lstadd_front(&teste, teste1);

    printf("%s", (char *)(*teste).content);

}  */
