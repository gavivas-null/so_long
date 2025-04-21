/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:12:38 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/21 21:26:08 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_close_windows(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_terminate(game->mlx);
	exit(0);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W)
		ft_move_player(game, game->player_x, game->player_y - 1);
	else if (keydata.key == MLX_KEY_A)
		ft_move_player(game, game->player_x - 1, game->player_y);
	else if (keydata.key == MLX_KEY_S)
		ft_move_player(game, game->player_x, game->player_y + 1);
	else if (keydata.key == MLX_KEY_D)
		ft_move_player(game, game->player_x + 1, game->player_y);
}

void	ft_move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		ft_disable_collect_at(game, new_x, new_y);
		game->point++;
		ft_printf("Coleccionable %d\n", game->point);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->tx.player->instances[0].x = new_x * TILE;
	game->tx.player->instances[0].y = new_y * TILE;
	game->moves++;
	ft_printf("Movimiento %d\n", game->moves);
	if ((game->map[new_y][new_x] == 'E')
		&& (game->point == game->total_collectibles))
	{
		ft_printf("WINNER\n");
		mlx_close_window(game->mlx);
	}
}
