/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:52:34 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:55:42 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* int	main()
{
	int	valor = 42;
    t_list *node = ft_lstnew(&valor);
    if (node)
    {
		printf("direccion hexa del nodo: %p\n", (void *)node);
        printf("Contenido del nodo: %d\n", *(int *)(node->content));
		free(node);
    }
    else
        printf("Error al crear el nodo\n");
    return 0;
} */