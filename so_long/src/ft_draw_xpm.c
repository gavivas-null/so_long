/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:30:43 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/02 22:31:55 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_floor(char **map, void *mlx, void *win, void *grass) //imprime en la ventana el tileset.
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (map[y][x]) //si hay xolumnas en la fila entra.
		{
			mlx_put_image_to_window(mlx, win, grass, (x * TILE), (y * TILE));
			x++; //cambia de columna.
		}
		y++; //cambia de fila.
	}
}