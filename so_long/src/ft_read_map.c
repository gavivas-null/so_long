/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:33:27 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/02 21:27:18 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_lst_2_array(t_list *list) //convierte una lista en un doble array.
{
	int		size;
	int		i;
	char	**array;

	size = ft_lstsize(list); //tamaño de la lista
	array = ft_calloc(sizeof(char *), size + 1); //crea un array para almacenar cada contenido de la lista.
	i = 0;
	while (list) //si la lista existe
	{
		array[i] = ft_strdup(list->content); //duplica el contenido de cada nodo en un doble puntero de arrays (cada lugar en el array guardara cada contenido de la lista).
		list = list->next; //la lista apunta al siguiente nodo para que al sumarle 1 a i apunte al siguiente nodo.
		i++;
	}
	return (array); //retorna un doble arrays con el mapa.
}

char	**ft_read_map(char *filename) //lee el mapa
{
	t_list	*map_list = NULL;
	t_list	*node;
    int		fd;
	char	*line;
	char	**map;

	fd = open(filename, O_RDONLY); //abre el mapa .ber
	if (fd == -1) //si da error retorna error y null.
		return(ft_printf("error"), NULL);
	line = get_next_line(fd); //lee la primera linea usando gnl.
	while (line)
	{
		node = ft_lstnew(line); //guarda la linea en un nodo.
		ft_lstadd_back(&map_list, node); //añade el nodo a una lista (en el primer llamado se crea la lista) al final.
		line = get_next_line(fd); //vuelves a llamar a gnl para almacenar la siguiente linea o null.
	}
	free(line); //liberas line para evitar leaks.
	close(fd); //cierras el fd-archivo que se estaba leyendo.
	map = ft_lst_2_array(map_list); //conviertes en array la lista con el mapa.
	ft_lstclear(&map_list, free); //liberas-limpias la lista.
	return (map); //retornas el mapa como array.
}
