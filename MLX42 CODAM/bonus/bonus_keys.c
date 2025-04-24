/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:12:38 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/24 18:38:55 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_moves_bonus(t_game *game)
{
	char				*new_str;
	char				*str;

	str = ft_itoa(game->moves);
	new_str = ft_strjoin("Movimientos: ", str);
	if (game->move_txt)
		mlx_delete_image(game->mlx, game->move_txt);
	game->move_txt = mlx_put_string(game->mlx, new_str, 5, 5);
	free(str);
	free(new_str);
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
	{
		game->player.direction = 'W';
		ft_move_player(game, game->player_x, game->player_y - 1);
	}
	else if (keydata.key == MLX_KEY_A)
	{
		game->player.direction = 'A';
		ft_move_player(game, game->player_x - 1, game->player_y);
	}
	ft_key_hook2(keydata, game);
}

void	ft_key_hook2(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_S)
	{
		game->player.direction = 'S';
		ft_move_player(game, game->player_x, game->player_y + 1);
	}
	else if (keydata.key == MLX_KEY_D)
	{
		game->player.direction = 'D';
		ft_move_player(game, game->player_x + 1, game->player_y);
	}
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
	update_player_sprites(game, &game->player);
	update_enemy_sprites(game, &game->enemy);
	game->moves++;
	draw_moves_bonus(game);
	end_game(game, new_x, new_y);
}
