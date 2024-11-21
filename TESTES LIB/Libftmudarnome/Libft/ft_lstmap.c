/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:08:55 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/04/24 19:03:26 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resultado;
	t_list	*tempresultado;

	if (lst != NULL && f != NULL)
	{
		resultado = ft_lstnew(f(lst->content));
		tempresultado = resultado;
		while (lst->next)
		{
			lst = lst->next;
			tempresultado->next = ft_lstnew(ft_strdup((f(lst->content))));
			if (tempresultado->next == NULL)
			{
				ft_lstclear(&resultado, del);
				return (NULL);
			}
			tempresultado = tempresultado->next;
		}
		return (resultado);
	}
	return (NULL);
}
