/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:41:02 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/02 23:12:56 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_get_map_size(char **map, int *width, int *height) //obtener el tamaño del mapa.
{
	if (!map || !map[0])
	{
		*width = 0;
		*height = 0;
		return ;
	}
	*height = 0; //comienza con la altura en 0.
	*width = ft_strlen(map[0]); //calcula el numero de columnas.
	while (map[*height]) // cuenta las filas.
		(*height)++; //recorre el mapa contando las filas hasta llegar a NULL.
}