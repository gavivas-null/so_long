/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_validate_map1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:31:51 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/25 23:02:46 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* int	check_map_size(t_game *game)
{
	int	map_w;
	int	map_h;

	map_w = game->width * TILE;
	map_h = game->height * TILE;
	mlx_get_monitor_size(0, &game->screen_w, &game->screen_h);
	if (map_w > game->screen_w || map_h > game->screen_h)
		return (ft_printf("Mapa demasiado grande"), 0);
	return (1);
} */

int	ft_check_walls(t_game *game)
{
	int	x;
	int	y;

	ft_get_map_size(game);
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (ft_printf("Error\nLos bordes deben ser todo '1'.\n"), 0);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (ft_printf("Error\nLos laterales deben ser todo '1'.\n"), 0);
		y++;
	}
	return (1);
}

int	ft_check_elements(t_game *game, int p_count, int e_count, int c_count)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!ft_strrchr("01PCEX", game->map[y][x]))
				return (ft_printf("Error\nMapa no válido.\n"), 0);
			if (game->map[y][x] == 'P')
				p_count++;
			if (game->map[y][x] == 'E')
				e_count++;
			if (game->map[y][x] == 'C')
				c_count++;
			x++;
		}
		y++;
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (ft_printf("Error\nMapa no válido.\n"), 0);
	return (1);
}

int	ft_check_rectangular(t_game *game)
{
	int		y;
	size_t	i;

	y = 0;
	i = ft_strlen(game->map[0]);
	while (game->map[y])
	{
		if (ft_strlen(game->map[y]) != i)
			return (ft_printf("Error\nMapa no valido.\n"), 0);
		y++;
	}
	return (1);
}

int	ft_validate_map(t_game *game)
{
/* 	if (!check_map_size(game))
		return (0); */
	if (!ft_check_rectangular(game))
		return (0);
	if (!ft_check_walls(game))
		return (0);
	if (!ft_check_elements(game, 0, 0, 0))
		return (0);
	if (!ft_validate_path(game))
		return (0);
	return (1);
}
