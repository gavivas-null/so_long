/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:55:26 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/03 21:37:21 by gavivas-         ###   ########.fr       */
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
	tx->player = mlx_xpm_file_to_image(mlx,
			"textures/prota_frontal2.xpm", &w, &h);
}

void	ft_draw_all_textures(char **map, void *mlx, void *win, t_textures *tx)
{
	ft_draw_floor(map, mlx, win, tx->grass);
	ft_draw_walls(map, mlx, win, tx->wall);
	ft_draw_exit(map, mlx, win, tx->exit);
	ft_draw_collect(map, mlx, win, tx->collect);
	ft_draw_player(map, mlx, win, tx->player);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	t_textures	tx;

	mlx = mlx_init();
	map = ft_read_map("maps/invalids/invalid_map1.ber");
	ft_get_map_size(map, &width, &height);
	if (!ft_validate_map(map))
		return (free(map), 1);
	win = mlx_new_window(mlx, width * TILE, height * TILE, "so_long");
	ft_load_textures(mlx, &tx);
	ft_draw_all_textures(map, mlx, win, &tx);
	mlx_loop(mlx);
	return (0);
}
