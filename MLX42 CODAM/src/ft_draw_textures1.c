/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:30:43 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/15 20:36:01 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_floor(t_game *game, t_textures *tx) //imprime en la ventana el tileset.
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (game->map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (game->map[y][x]) //si hay columnas en la fila entra.
		{
			mlx_image_to_window(game->mlx, tx->grass, (x * TILE), (y * TILE));
			x++; //cambia de columna.
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_walls(t_game *game, t_textures *tx)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (game->map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (game->map[y][x]) //si hay columnas en la fila entra.
		{
			if (game->map[y][x] == '1') //si hay una pared
			{
				mlx_image_to_window(game->mlx, tx->wall, (x * TILE), (y * TILE));
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_exit(t_game *game, t_textures *tx)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (game->map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (game->map[y][x]) //si hay columnas en la fila entra.
		{
			if (game->map[y][x] == 'E') //si hay una salida
			{
				mlx_image_to_window(game->mlx, tx->exit, (x * TILE), (y * TILE));
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_collect(t_game *game, t_textures *tx)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	game->total_collectibles = 0;
	while (game->map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (game->map[y][x]) //si hay columnas en la fila entra.
		{
			if (game->map[y][x] == 'C') //si hay un coleccionable.
			{
				mlx_image_to_window(game->mlx, tx->collect, (x * TILE), (y * TILE));
				game->total_collectibles++;
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}

void	ft_draw_player(t_game *game, t_textures *tx)
{
	int	x; //cada columna del mapa.
	int	y; //cada fila del mapa.

	y = 0;
	while (game->map[y]) //si hay filas en el mapa entra.
	{
		x = 0;
		while (game->map[y][x]) //si hay columnas en la fila entra.
		{
			if (game->map[y][x] == 'P') //si hay un jugador.
			{
				mlx_image_to_window(game->mlx, tx->player, (x * TILE), (y * TILE));
				game->player_x = x;
				game->player_y = y;
				game->player_img = tx->player;
				return;
			}
			x++; //cambia de columna.	
		}
		y++; //cambia de fila.
	}
}
