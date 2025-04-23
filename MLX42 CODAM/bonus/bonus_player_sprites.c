/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:23:02 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/23 19:57:26 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_player_sprites(t_game *game)
{
	game->player.right[0] = ft_load_png(game->mlx, "textures/player_right1.png");
	game->player.right[1] = ft_load_png(game->mlx, "textures/player_right2.png");
	game->player.right[2] = ft_load_png(game->mlx, "textures/player_right3.png");
	game->player.left[0] = ft_load_png(game->mlx, "textures/player_left1.png");
	game->player.left[1] = ft_load_png(game->mlx, "textures/player_left2.png");
	game->player.left[2] = ft_load_png(game->mlx, "textures/player_left3.png");
	game->player.front[0] = ft_load_png(game->mlx, "textures/player_front1.png");
	game->player.front[1] = ft_load_png(game->mlx, "textures/player_front2.png");
	game->player.front[2] = ft_load_png(game->mlx, "textures/player_front3.png");
	game->player.back[0] = ft_load_png(game->mlx, "textures/player_back1.png");
	game->player.back[1] = ft_load_png(game->mlx, "textures/player_back2.png");
	game->player.back[2] = ft_load_png(game->mlx, "textures/player_back3.png");
}

void	disable_all_player_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		game->player.right[i]->enabled = false;
		game->player.left[i]->enabled = false;
		game->player.front[i]->enabled = false;
		game->player.back[i]->enabled = false;
		i++;
	}
}

void	ft_player_sprites(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->player.front[0], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.front[1], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.front[2], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.back[0], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.back[1], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.back[2], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.left[0], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.left[1], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.left[2], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.right[0], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.right[1], x * TILE, y * TILE);
	mlx_image_to_window(game->mlx, game->player.right[2], x * TILE, y * TILE);
}

void	update_player_sprites(t_game *game, t_player *player)
{
	if (player->anim_frame == 2)
		player->anim_frame = 0;
	else
		player->anim_frame++;
	disable_all_player_sprites(game);
	if (player->direction == 'W')
	{
		player->back[player->anim_frame]->enabled = true;
		player->back[player->anim_frame]->instances[0].x = game->player_x * TILE;
		player->back[player->anim_frame]->instances[0].y = game->player_y * TILE;
	}
	else if (player->direction == 'S')
	{
		player->front[player->anim_frame]->enabled = true;
		player->front[player->anim_frame]->instances[0].x = game->player_x * TILE;
		player->front[player->anim_frame]->instances[0].y = game->player_y * TILE;
	}
	else if (player->direction == 'A')
	{
		player->left[player->anim_frame]->enabled = true;
		player->left[player->anim_frame]->instances[0].x = game->player_x * TILE;
		player->left[player->anim_frame]->instances[0].y = game->player_y * TILE;
	}
	else if (player->direction == 'D')
	{
		player->right[player->anim_frame]->enabled = true;
		player->right[player->anim_frame]->instances[0].x = game->player_x * TILE;
		player->right[player->anim_frame]->instances[0].y = game->player_y * TILE;
	}
}

