/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:32 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:56:28 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* int	main(void)
{
	char	str[];

	str[] = "hello world";
	printf("Antes: %s\n", str);
	// Definición de la función to_uppercase dentro del main.
	void to_uppercase(unsigned int index, char *c)
	{
		if (*c >= 'a' && *c <= 'z')
		{
			*c = *c - 'a' + 'A';
		}
	}
	ft_striteri(str, to_uppercase);
	// Aplica la función to_uppercase a cada carácter. 
	printf("Después: %s\n", str);
}*/