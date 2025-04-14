/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:33:39 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/14 22:34:38 by gavivas-         ###   ########.fr       */
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

void	ft_load_textures(mlx_t *mlx, t_textures *tx)
{
	tx->grass = ft_load_png(mlx, "textures/tileset.png");
	tx->wall = ft_load_png(mlx, "textures/pared.png");
	tx->exit = ft_load_png(mlx, "textures/salida1.png");
	tx->collect = ft_load_png(mlx, "textures/premio1.png");
	tx->player = ft_load_png(mlx, "textures/prota_frontal2.png");
}

void	ft_draw_all_textures(t_game *game, t_textures *tx)
{
	ft_draw_floor(game, tx);
	ft_draw_walls(game, tx);
	ft_draw_exit(game, tx);
	ft_draw_collect(game, tx);
	ft_draw_player(game, tx);
}