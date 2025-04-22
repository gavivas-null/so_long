/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:23:02 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/22 22:51:28 by gavivas-         ###   ########.fr       */
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

void	print_sprites(t_game *game, int x, int y)
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

void	update_player_sprites(t_game *game)
{
	if(game->player.anim_frame == 2)
		game->player.anim_frame = 0;
	else
		game->player.anim_frame++;
	game->player.right[0]->enabled = false;
	game->player.right[1]->enabled = false;
	game->player.right[2]->enabled = false;
	game->player.left[0]->enabled = false;
	game->player.left[1]->enabled = false;
	game->player.left[2]->enabled = false;
	game->player.front[0]->enabled = false;
	game->player.front[1]->enabled = false;
	game->player.front[2]->enabled = false;
	game->player.back[0]->enabled = false;
	game->player.back[1]->enabled = false;
	game->player.back[2]->enabled = false;
	if (game->player.direction == 'W')
	{
		game->player.back[game->player.anim_frame]->enabled = true;
		game->player.back[game->player.anim_frame]->instances[0].x = game->player_x * TILE;
		game->player.back[game->player.anim_frame]->instances[0].y = game->player_y * TILE;
	}
	else if (game->player.direction == 'S')
	{
		game->player.front[game->player.anim_frame]->enabled = true;
		game->player.front[game->player.anim_frame]->instances[0].x = game->player_x * TILE;
		game->player.front[game->player.anim_frame]->instances[0].y = game->player_y * TILE;
	}
	else if (game->player.direction == 'A')
	{
		game->player.left[game->player.anim_frame]->enabled = true;
		game->player.left[game->player.anim_frame]->instances[0].x = game->player_x * TILE;
		game->player.left[game->player.anim_frame]->instances[0].y = game->player_y * TILE;
	}
	else if (game->player.direction == 'D')
	{
		game->player.right[game->player.anim_frame]->enabled = true;
		game->player.right[game->player.anim_frame]->instances[0].x = game->player_x * TILE;
		game->player.right[game->player.anim_frame]->instances[0].y = game->player_y * TILE;
	}
}
