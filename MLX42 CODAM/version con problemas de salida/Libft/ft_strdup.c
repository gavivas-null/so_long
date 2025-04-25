/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:28 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:56:26 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*cpy;

	i = 0;
	size = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * size);
	if (cpy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/* 
int main() {
    const char *s1 = "Hola Mundo!";
    char *duplicated_string;

    // Llamada a la función ft_strdup
    duplicated_string = ft_strdup(((void *)0));

    // Verificar si la función devolvió NULL (lo que indicaría un error)
    if (duplicated_string == NULL) 
	{
        printf("Error: ft_strdup devolvió NULL.\n");
        return 1;
    }

    // Imprimir la cadena duplicada
    printf("Cadena duplicada: %s\n", duplicated_string);

    // Liberar la memoria asignada por ft_strdup
    free(duplicated_string);

    return 0;
}*/