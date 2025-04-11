/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:55:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/11 21:24:26 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_textures(void *mlx, t_textures *tx)
{
	int		w;
	int		h;

	tx->grass = mlx_xpm_file_to_image(mlx, "textures/tileset.xpm", &w, &h);
	tx->wall = mlx_xpm_file_to_image(mlx, "textures/pared.xpm", &w, &h);
	tx->exit = mlx_xpm_file_to_image(mlx, "textures/salida1.xpm", &w, &h);
	tx->collect = mlx_xpm_file_to_image(mlx, "textures/premio1.xpm", &w, &h);
	tx->player = mlx_xpm_file_to_image(mlx,	"textures/prota_frontal2.xpm", &w, &h);
}

void	ft_draw_all_textures(t_game *game, t_textures *tx)
{
	ft_draw_floor(game, tx);
	ft_draw_walls(game, tx);
	ft_draw_exit(game, tx);
	ft_draw_collect(game, tx);
	ft_draw_player(game, tx);
}

int	main(void)
{

	t_textures	tx;
	t_game		game;

	game.mlx = mlx_init();
	game.map = ft_read_map("maps/valids/map2.ber");
	ft_get_map_size(&game);
	if (!game.map || !ft_validate_map(&game))
		return (free(game.map), 1);
	game.win = mlx_new_window(game.mlx, game.width * TILE, game.height * TILE, "so_long");
	ft_load_textures(game.mlx, &tx);
	ft_draw_all_textures(&game, &tx);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
