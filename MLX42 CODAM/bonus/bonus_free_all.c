/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:06:22 by gavivas-          #+#    #+#             */
/*   Updated: 2025/05/02 19:19:38 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clean_exit(t_game *game, int code)
{
	if (game->move_txt)
		mlx_delete_image(game->mlx, game->move_txt);
	if (game->map)
		ft_free_split(game->map);
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	ft_printf("Se limpió todo\n");
	exit(code);
}
