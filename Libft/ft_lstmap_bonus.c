/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:52:30 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:55:40 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*final;
	void	*fcontent;

	final = 0;
	while (lst)
	{
		fcontent = f(lst->content);
		aux = ft_lstnew(fcontent);
		if (!aux)
		{
			del(fcontent);
			ft_lstclear(&aux, del);
		}
		ft_lstadd_back(&final, aux);
		lst = lst->next;
	}
	return (final);
}
