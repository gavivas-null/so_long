/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:52:49 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 18:55:52 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!s && !d)
		return (0);
	if (s > d)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dst);
}
/* int	main(void)
{
	char s[] = "rem ipssum dolor sit a";
	char d[50] = "CDFG";
	size_t l = 10;

	printf("%s\n", ft_memmove(d, s, l));
	printf("%s", memmove(d, s, l));
	return (0);
} */