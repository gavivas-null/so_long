/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:12:38 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/11 21:33:29 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	(void)game;

	if (keycode == KEY_ESC)
	{
		ft_printf("Tecla ESC presionada: %d\n", keycode);
		exit(0);
	}
	if (keycode == KEY_W)
	{
		ft_printf("Tecla W presionada: %d\n", keycode);
	}
	if (keycode == KEY_A)
	{
		ft_printf("Tecla A presionada: %d\n", keycode);
	}
	if (keycode == KEY_S)
	{
		ft_printf("Tecla S presionada: %d\n", keycode);
	}
	if (keycode == KEY_D)
	{
		ft_printf("Tecla D presionada: %d\n", keycode);
	}
	return (0);
}
