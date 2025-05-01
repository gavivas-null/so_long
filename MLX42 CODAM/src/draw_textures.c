/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:30:43 by gavivas-          #+#    #+#             */
/*   Updated: 2025/05/01 21:36:42 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_map(t_game *game, t_textures *tx, int x, int y)
{
	game->total_collectibles = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, tx->grass,
				(x * TILE), (y * TILE));
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, tx->wall,
					(x * TILE), (y * TILE));
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, tx->exit,
					(x * TILE), (y * TILE));
			else if (game->map[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, tx->collect,
					(x * TILE), (y * TILE));
				game->total_collectibles++;
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_game *game, t_textures *tx)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, tx->player,
					(x * TILE), (y * TILE));
				game->player_x = x;
				game->player_y = y;
				game->player_img = tx->player;
				return ;
			}
			x++;
		}
		y++;
	}
}

mlx_image_t	*ft_load_png(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("❌ Error al cargar %s\n", path);
		clean_exit(game, 0);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		ft_printf("❌ Error al crear imagen desde %s\n", path);
		clean_exit(game, 0);
	}
	return (image);
}

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

void	ft_draw_all_textures(t_game *game, t_textures *tx)
{
	tx->grass = ft_load_png(game, "textures/tileset.png");
	tx->wall = ft_load_png(game, "textures/wall.png");
	tx->exit = ft_load_png(game, "textures/exit1.png");
	tx->collect = ft_load_png(game, "textures/collectable1.png");
	tx->player = ft_load_png(game, "textures/player_f1.png");
	ft_draw_map(game, tx, 0, 0);
	ft_draw_player(game, tx);
}
