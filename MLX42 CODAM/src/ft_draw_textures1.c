/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:30:43 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/21 20:10:49 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_floor(t_game *game, t_textures *tx)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, tx->grass, (x * TILE), (y * TILE));
			x++;
		}
		y++;
	}
}

void	ft_draw_walls(t_game *game, t_textures *tx)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				mlx_image_to_window(game->mlx, tx->wall,
					(x * TILE), (y * TILE));
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_exit(t_game *game, t_textures *tx)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, tx->exit,
					(x * TILE), (y * TILE));
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_collect(t_game *game, t_textures *tx)
{
	int	x;
	int	y;

	y = 0;
	game->total_collectibles = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, tx->collect,
					(x * TILE), (y * TILE));
				game->total_collectibles++;
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_game *game, t_textures *tx)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, tx->player,
					(x * TILE), (y * TILE));
				game->player_x = x;
				game->player_y = y;
				game->player_img = tx->player;
				return ;
			}
			x++;
		}
		y++;
	}
}
