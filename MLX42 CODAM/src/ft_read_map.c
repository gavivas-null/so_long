/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:41:02 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/21 20:12:13 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_get_map_size(t_game *game)
{
	if (!game->map)
	{
		game->width = 0;
		game->height = 0;
		return ;
	}
	game->width = ft_strlen(game->map[0]);
	game->height = 0;
	while (game->map[game->height])
		game->height++;
}

char	**ft_lst_2_array(t_list *list)
{
	int		size;
	int		i;
	char	**array;

	size = ft_lstsize(list);
	array = ft_calloc(sizeof(char *), size + 1);
	if (!array)
		return (NULL);
	i = 0;
	while (list)
	{
		array[i] = ft_strdup(list->content);
		list = list->next;
		i++;
	}
	return (array);
}

char	**ft_read_map(char *filename)
{
	t_list	*map_list;
	t_list	*node;
	int		fd;
	char	*line;
	char	**map;

	map_list = NULL;
	if (!filename)
		return (ft_printf("Error\nNombre del archivo nulo.\n"), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nNo se pudo abrir el archivo.\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line && ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		node = ft_lstnew(line);
		ft_lstadd_back(&map_list, node);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map = ft_lst_2_array(map_list);
	return (ft_lstclear(&map_list, free), map);
}
