/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:31:51 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/17 21:03:54 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_valid_chars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!ft_strchr("10PCE", game->map[y][x]))
			{
				return (ft_printf("Error\nCarácter inválido '%c' en el mapa.\n",
						game->map[y][x]), 0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_walls(t_game *game)
{
	int	x;
	int	y;

	ft_get_map_size(game);
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1')
			return (ft_printf(
					"Error\nEl borde superior debe ser todo '1'.\n"), 0);
		if (game->map[game->height - 1][x] != '1')
			return (ft_printf("Error\nEl borde inferior debe ser todo '1'.\n"), 0);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1')
			return (ft_printf("Error\nEl borde lateral izquierdo debe ser todo '1'.\n"), 0);
		if (game->map[y][game->width - 1] != '1')
			return (ft_printf("Error\nEl borde lateral derecho debe ser todo '1'.\n"), 0);
		y++;
	}
	return (1);
}

int	ft_check_required_elements(t_game *game)
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	x;
	int	y;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
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
		return (ft_printf(
				"Error\nEl mapa debe tener 1 'P', 1 'E' y al menos 1 'C'.\n"), 0);
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
			return (ft_printf(
					"Error\nLas filas del mapa no tienen la misma longitud.\n"), 0);
		y++;
	}
	return (1);
}

int	ft_validate_map(t_game *game)
{
	if (!ft_check_valid_chars(game))
		return (0);
	if (!ft_check_walls(game))
		return (0);
	if (!ft_check_required_elements(game))
		return (0);
	if (!ft_check_rectangular(game))
		return (0);
	if (!ft_validate_path(game))
		return (0);
	return (1);
}
