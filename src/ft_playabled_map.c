/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playabled_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:11:37 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/09 21:17:32 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	**ft_copy_map(char **map)
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
	int x;
	int y;

    y = 0;
    while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P') 
			{
				x_player = x;
				y_player = y;
				return (0);
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}