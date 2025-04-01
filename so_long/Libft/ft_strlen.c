/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:53 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:56:40 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}
/*
int	main(void)
{
	char	*len;

	len = "Muy buenas a todos Guapisimos";

	printf("%zu \n", ft_strlen(len));
	printf("%zu", strlen(len));
	return (0);
}*/