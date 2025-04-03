/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:30:43 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/03 21:40:05 by gavivas-         ###   ########.fr       */
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
		while (map[y][x]) //si hay columnas en la fila entra.
		{
			mlx_put_image_to_window(mlx, win, grass, (x * TILE), (y * TILE));
			x++; //cambia de columna.
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_walls(char **map, void *mlx, void *win, void *wall)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (map[y][x]) //si hay columnas en la fila entra.
		{
			if (map[y][x] == '1') //si hay una pared
			{
				mlx_put_image_to_window(mlx, win, wall, (x * TILE), (y * TILE));
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_exit(char **map, void *mlx, void *win, void *exit)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (map[y][x]) //si hay columnas en la fila entra.
		{
			if (map[y][x] == 'E') //si hay una salida
			{
				mlx_put_image_to_window(mlx, win, exit, (x * TILE), (y * TILE));
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_collect(char **map, void *mlx, void *win, void *collect)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (map[y][x]) //si hay columnas en la fila entra.
		{
			if (map[y][x] == 'C') //si hay un coleccionable.
			{
				mlx_put_image_to_window(mlx, win, collect, (x * TILE), (y * TILE));
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_player(char **map, void *mlx, void *win, void *player)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (map[y][x]) //si hay columnas en la fila entra.
		{
			if (map[y][x] == 'P') //si hay un jugador.
			{
				mlx_put_image_to_window(mlx, win, player, (x * TILE), (y * TILE));
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}
