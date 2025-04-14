/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:54:38 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:56:52 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	substr = malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
/* #include <stdio.h>
int main() {
    char const *s = "Hola Mundo!";
    unsigned int start = 12;
    size_t len = 2;
    char *substr;

    // Llamada a la función ft_substr
    substr = ft_substr(s, start, len);

    // Verificar si la función devolvió NULL (lo que indicaría un error)
    if (substr == NULL) {
        printf("Error: ft_substr devolvió NULL.\n");
        return 1;
    }

    // Imprimir la subcadena
    printf("Subcadena: >%s<\n", substr);

    // Liberar la memoria asignada por ft_substr
    free(substr);

    return 0;
} */