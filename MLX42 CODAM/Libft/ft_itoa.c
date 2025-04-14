/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:51:53 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 19:56:33 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_special_cases(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

static void	ft_while(int n, size_t len, char *new)
{
	while (n != 0)
	{
		new[--len] = n % 10 + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	size_t	len;
	char	*new;

	i = 0;
	if (n == 0 || n == -2147483648)
		return (ft_special_cases(n));
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	len = ft_count_digits(n);
	if (i == 1)
		len += 1;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	new[len] = '\0';
	new[0] = '-';
	ft_while(n, len, new);
	return (new);
}

// int	main(void)
// {
// 	int n = -2147483648;
// 	char *str = ft_itoa(n);
// 	ft_putstr_fd(str, 1);
// 	return (0);
// }