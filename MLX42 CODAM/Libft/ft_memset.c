/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:52:53 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:56:03 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *) b)[i] = c;
		i++;
	}
	return (b);
}
/*
int     main(void)
{
        int     c = 'f';
        size_t  d = 10;
        unsigned char f[30] = "muy buenas guapisimos";

        printf("%s \n", ft_memset(f, c, d));
        printf("%s", memset(f, c, d));
        return (0);
}*/
