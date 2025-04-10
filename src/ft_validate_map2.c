/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:11:37 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/10 20:33:57 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_copy_map(char **map)
{
	char	**copy; // donde se guarda el mapa duplicado.
	int		height; // saber cuantass filas tiene el mapa.
	int		i; //contador para recorrer el array.

	ft_get_map_size(map, NULL, &height);
	copy = ft_calloc(sizeof(char *), height + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	ft_find_player(char **map, int *x_player, int *y_player) 
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P') 
			{
				*x_player = x;
				*y_player = y;
				return;
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}

void ft_flood_fill(char **map, int x, int y) //revisa si el mapa es jugable.
{
	int	width;
	int	height;

	ft_get_map_size(map, &width, &height);
	if ((x < 0 || y < 0) || (x >= width || y >= height))
		return;
	else if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	map[y][x] = 'V';
	ft_flood_fill(map, x + 1, y); //revisa la derecha
	ft_flood_fill(map, x - 1, y); //revisa la izquierda
	ft_flood_fill(map, x, y + 1); //revisa abajo
	ft_flood_fill(map, x, y - 1); //revisa arriba
}

int	ft_map_playable(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				ft_printf("Error\nQuedaron coleccionables o salida sin alcanzar.\n");
				return (0);
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
	return (1);
}

int	ft_validate_path(char **map)
{
	char	**copy;
	int		x;
	int		y;

	copy = ft_copy_map(map);
	if (!copy)
		return (0);
	ft_find_player(copy, &x, &y);
	ft_flood_fill(copy, x, y);
	if (!ft_map_playable(copy))
	{
		ft_printf("El mapa no es jugable.\n");
		ft_free_split(copy);
		return (0);
	}
	ft_free_split(copy);
	return (1);
}
