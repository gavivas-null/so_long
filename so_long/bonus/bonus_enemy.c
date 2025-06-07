/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:09:07 by gavivas-          #+#    #+#             */
/*   Updated: 2025/05/02 18:33:46 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_enemy_sprites(t_game *game)
{
	game->enemy.sprites[0] = ft_load_png(game, "textures/enemy_f1.png");
	game->enemy.sprites[2] = ft_load_png(game, "textures/enemy_l1.png");
	game->enemy.sprites[1] = ft_load_png(game, "textures/enemy_b1.png");
	game->enemy.sprites[3] = ft_load_png(game, "textures/enemy_r1.png");
}

void	disable_all_enemy_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->enemy.sprites[i]->enabled = false;
		i++;
	}
}

void	ft_enemy_sprites(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->enemy.sprites[0], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->enemy.sprites[1], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->enemy.sprites[2], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->enemy.sprites[3], x * TILE, y * TILE);
}

void	update_enemy_sprites(t_game *game, t_enemy *enemy)
{
	if (enemy->anim_frame == 3)
		enemy->anim_frame = 0;
	else
		enemy->anim_frame++;
	disable_all_enemy_sprites(game);
	enemy->sprites[enemy->anim_frame]->enabled = true;
}

void	ft_draw_enemy(t_game *game, t_enemy *enemy)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'X')
			{
				enemy->enemy_x = x;
				enemy->enemy_y = y;
				ft_enemy_sprites(game, x, y);
				update_enemy_sprites(game, &game->enemy);
			}
			x++;
		}
		y++;
	}
}
