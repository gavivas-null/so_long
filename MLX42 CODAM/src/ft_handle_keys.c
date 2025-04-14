/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:12:38 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/14 19:42:20 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_key_hook(void *param)
{
	t_game *game = (t_game *)param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("ESC presionado\n");
		mlx_close_window(game->mlx);
	}
		if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		ft_printf("W presionado\n");
	}
		if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		ft_printf("A presionado\n");
	}
		if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		ft_printf("S presionado\n");
	}
		if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		ft_printf("D presionado\n");
	}
}
