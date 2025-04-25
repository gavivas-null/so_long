/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exit_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:19:33 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/25 23:05:50 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_exit_sprites(t_game *game)
{
	game->exit.sprites[0] = ft_load_png(game->mlx, "textures/exit1.png", game);
	game->exit.sprites[1] = ft_load_png(game->mlx, "textures/exit2.png", game);
}

void	disable_all_exit_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		game->exit.sprites[i]->enabled = false;
		i++;
	}
}

void	ft_exit_sprites(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->exit.sprites[0], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->exit.sprites[1], x * TILE, y * TILE);
}

void	update_exit_sprites(t_game *game, t_exit *exit)
{
	if (exit->anim_frame != 1)
	{
		exit->anim_frame++;
	}
	disable_all_exit_sprites(game);
	exit->sprites[exit->anim_frame]->enabled = true;
}

void	ft_draw_exit(t_game *game, t_exit *exit)
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
				exit->exit_x = x;
				exit->exit_y = y;
				ft_exit_sprites(game, x, y);
			}
			x++;
		}
		y++;
	}
}
