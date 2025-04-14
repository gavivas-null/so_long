/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:55:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/14 22:35:47 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	main(void)
{
	t_game		game;
	
	game.map = ft_read_map("maps/valids/map2.ber");
	ft_get_map_size(&game);
	if (!game.map || !ft_validate_map(&game))
		return (free(game.map), 1);
	game.mlx =mlx_init(game.width * TILE, game.height * TILE, "so_long", true);
	ft_load_textures(game.mlx, &game.tx);
	ft_draw_all_textures(&game, &game.tx);
	mlx_loop_hook(game.mlx, ft_key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}