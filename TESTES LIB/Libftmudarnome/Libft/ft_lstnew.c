/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:45:36 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/22 13:46:54 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* int main(void) {
    char str[] = "Hello, world!";
    t_list *teste;
    teste = ft_lstnew(str);

    printf("%s", (char *)teste->content);
} */

// int main(void) {
//     int        i;
//     t_list *elem;
//     i = 42;

//     elem = ft_lstnew(&i);

//     printf("%p", elem->content);

// }
