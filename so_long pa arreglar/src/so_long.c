/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:55:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/17 21:09:45 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_disable_collect_at(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < (game->tx.collect->count))
	{
		if (((game->tx.collect->instances[i].x) == (x * TILE))
			&& ((game->tx.collect->instances[i].y) == (y * TILE)))
		{
			game->tx.collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

int	ft_check_ber(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (!ft_strncmp(filename + len - 4, ".ber", 4));
}

void	ft_close_windows(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_terminate(game->mlx);
	exit(0);
}

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
	if (!game.map || !ft_validate_map(&game))
		return (free(game.map), 1);
	game.mlx = mlx_init(game.width * TILE, game.height * TILE, "so_long", true);
	ft_load_textures(game.mlx, &game, &game.tx);
	mlx_key_hook(game.mlx, ft_key_hook, &game);
	mlx_close_hook(game.mlx, ft_close_windows, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}
