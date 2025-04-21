/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:08:25 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/21 21:31:10 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_moves_bonus(t_game *game)
{
	char		*new_str;
	char		*str;
	mlx_image_t	*moves_text;

	str = ft_itoa(game->moves);
	new_str = ft_strjoin("Movimientos: ", str);
	moves_text = mlx_put_string(game->mlx, new_str, 5, 5);
	free(str);
	free(new_str);
}