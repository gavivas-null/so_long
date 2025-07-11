/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:55:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/05/05 16:51:50 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (ft_printf(
				"Error\nDebes pasar un solo mapa como argumento\n"), 1);
	if (!ft_check_ber(argv[1]))
		return (ft_printf("Error\nEl archivo debe tener extensión .ber\n"), 1);
	game.map = ft_read_map(argv[1]);
	game.moves = 0;
	game.point = 0;
	ft_get_map_size(&game);
	game.mlx = mlx_init(game.width * TILE, game.height * TILE, "so_long", true);
	mlx_get_monitor_size(0, &game.screen_w, &game.screen_h);
	if (!game.map || !ft_validate_map(&game))
		clean_exit(&game, 0);
	ft_draw_all_textures(&game, &game.tx);
	mlx_key_hook(game.mlx, ft_key_hook, &game);
	mlx_close_hook(game.mlx, ft_close_windows, &game);
	mlx_loop(game.mlx);
	clean_exit(&game, 0);
	return (0);
}
