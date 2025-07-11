/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:05:24 by gavivas-          #+#    #+#             */
/*   Updated: 2025/05/02 19:35:44 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_int(t_game *game)
{
	game->moves = 0;
	game->point = 0;
	game->player.anim_frame = 0;
	game->enemy.anim_frame = 0;
	game->exit.anim_frame = 0;
	game->move_txt = NULL;
}

void	end_game(t_game *game, int new_x, int new_y)
{
	if (game->point == game->total_collectibles)
		update_exit_sprites(game, &game->exit);
	if ((game->map[new_y][new_x] == 'E')
		&& (game->point == game->total_collectibles))
	{
		ft_printf("WINNER\n");
		clean_exit(game, 0);
	}
	if (game->map[new_y][new_x] == 'X')
	{
		ft_printf("LOSER\n");
		clean_exit(game, 0);
	}
}

void	ft_close_windows(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clean_exit(game, 0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (ft_printf(
				"Error\nDebes pasar un solo mapa como argumentos\n"), 1);
	if (!ft_check_ber(argv[1]))
		return (ft_printf("Error\nEl archivo debe tener extensión .ber\n"), 1);
	game.map = ft_read_map(argv[1]);
	init_int(&game);
	ft_get_map_size(&game);
	game.mlx = mlx_init(game.width * TILE, game.height * TILE, "so_long", true);
	mlx_get_monitor_size(0, &game.screen_w, &game.screen_h);
	if (!game.map || !ft_validate_map(&game))
		clean_exit(&game, 0);
	load_player_sprites(&game);
	load_enemy_sprites(&game);
	load_exit_sprites(&game);
	ft_draw_all_textures(&game, &game.tx);
	mlx_key_hook(game.mlx, ft_key_hook, &game);
	mlx_close_hook(game.mlx, ft_close_windows, &game);
	mlx_loop(game.mlx);
	clean_exit(&game, 0);
	return (0);
}
