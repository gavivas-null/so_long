/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:10:40 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/02 21:31:49 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(void)
{
	char	**map;
	int		i;

	map = ft_read_map("maps/valids/map1.ber");
	if (!map)
		return (1);
	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	return (0);
}
