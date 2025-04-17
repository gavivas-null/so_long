/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:11:37 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/16 21:12:26 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_copy_map(t_game *game)
{
	char	**copy_map;
	int		i;

	ft_get_map_size(game);
	copy_map = ft_calloc(sizeof(char *), game->height + 1);
	if (!copy_map)
		return (NULL);
	i = 0;
	while (game->map[i])
	{
		copy_map[i] = ft_strdup(game->map[i]);
		if (!copy_map[i])
		{
			while (--i >= 0)
				free(copy_map[i]);
			free(copy_map);
			return (NULL);
		}
		i++;
	}
	return (copy_map);
}

void	ft_find_player(char **copy_map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (copy_map[y])
	{
		x = 0;
		while (copy_map[y][x])
		{
			if (copy_map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_flood_fill(char **copy_map, int x, int y, t_game *game)
{
	if ((x < 0 || y < 0) || (x >= game->width || y >= game->height))
		return ;
	else if (copy_map[y][x] == '1' || copy_map[y][x] == 'V')
		return ;
	copy_map[y][x] = 'V';
	ft_flood_fill(copy_map, x + 1, y, game);
	ft_flood_fill(copy_map, x - 1, y, game);
	ft_flood_fill(copy_map, x, y + 1, game);
	ft_flood_fill(copy_map, x, y - 1, game);
}

int	ft_map_playable(char **copy_map)
{
	int	x;
	int	y;

	y = 0;
	while (copy_map[y])
	{
		x = 0;
		while (copy_map[y][x])
		{
			if (copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
			{
				ft_printf(
					"Error\nQuedaron coleccionables o salida sin alcanzar.\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_validate_path(t_game *game)
{
	char	**copy_map;

	copy_map = ft_copy_map(game);
	if (!copy_map)
		return (0);
	ft_find_player(copy_map, game);
	ft_flood_fill(copy_map, game->player_x, game->player_y, game);
	if (!ft_map_playable(copy_map))
	{
		ft_printf("El mapa no es jugable.\n");
		ft_free_split(copy_map);
		return (0);
	}
	ft_free_split(copy_map);
	return (1);
}
