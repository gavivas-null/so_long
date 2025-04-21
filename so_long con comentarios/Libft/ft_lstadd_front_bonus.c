/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:52:00 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:55:30 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/* // Función para imprimir la lista
void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main()
{
	// Crear una lista con algunos nodos
	t_list *head = ft_lstnew("Nodo 2");
    head->next = ft_lstnew("Nodo 3");
    head->next->next = ft_lstnew("Nodo 4");

    // Imprimir la lista original
	printf("Lista original: ");
    print_list(head);

    // Crear un nuevo nodo y añadirlo al frente
    t_list *new_node = ft_lstnew("Nodo 1");
    ft_lstadd_front(&head, new_node);

    // Imprimir la lista después de añadir el nuevo nodo
    printf("Lista después de añadir al frente: ");
    print_list(head);

    // Liberar memoria (opcional, pero recomendado)
    t_list *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
} */