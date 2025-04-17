/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:30:43 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/16 22:47:17 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*ft_load_png(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("❌ Error al cargar %s\n", path);
		exit(1);
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		ft_printf("❌ Error al crear imagen desde %s\n", path);
		exit(1);
	}
	return (image);
}

void	ft_draw_by_char(t_game *game, mlx_image_t *img, char target)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (target == '\0' || game->map[y][x] == target)
				mlx_image_to_window(game->mlx, img, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}

void	ft_draw_collect(t_game *game, t_textures *tx)
{
	int	x;
	int	y;

	y = 0;
	game->total_collectibles = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
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

void	ft_load_textures(mlx_t *mlx, t_game *game, t_textures *tx)
{
	tx->grass = ft_load_png(mlx, "textures/tileset.png");
	tx->wall = ft_load_png(mlx, "textures/pared.png");
	tx->exit = ft_load_png(mlx, "textures/salida1.png");
	tx->collect = ft_load_png(mlx, "textures/premio1.png");
	tx->player = ft_load_png(mlx, "textures/prota_frontal2.png");
	ft_draw_by_char(game, tx->grass, '\0');
	ft_draw_by_char(game, tx->wall, '1');
	ft_draw_by_char(game, tx->exit, 'E');
	ft_draw_collect(game, tx);
	ft_draw_player(game, tx);
}
