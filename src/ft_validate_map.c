/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:31:51 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/03 21:20:57 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_valid_chars(char **map)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E') 
			{
				ft_printf("Error\n Carácter inválido '%c' en el mapa.\n", map[y][x]);
				return (0);
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
	return (1);
}

int	ft_check_walls(char **map) 
{
	int	width; //cantidad de columnas.
	int	height; //cantidad de filas.
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	ft_get_map_size(map, &width, &height); //obtinene el tamaño del mapa.
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1') //si la primera fila no es 1 da error.
		{
			ft_printf("Error\n El borde superior debe ser todo '1'.\n");
			return (0);
		}
		if (map[height - 1][x] != '1') //si la ultima fila no es 1 da error.
		{
			ft_printf("Error\n El borde inferior debe ser todo '1'.\n");
			return (0);
		}
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1') //Verifica que la primera columna (izquierda) de cada fila sea '1'
		{
			ft_printf("Error\n El borde lateral izquierdo debe ser todo '1'.\n");
			return (0);
		}
		if (map[y][width - 1] != '1') // Verifica que la última columna (derecha) de cada fila sea '1'
		{
			ft_printf("Error\n El borde lateral derecho debe ser todo '1'.\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_validate_map(char **map)
{
	if (!ft_check_valid_chars(map)) //chequea que sean caracteres validos.
		return (0);
	if (!ft_check_walls(map)) //chequea las paredes.
		return (0);
	return (1);
}
