/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:34 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/01 19:29:21 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_if(char const *str, va_list printf_arg, int i, int *count)
{
	i++;
	if (str[i] == 'c')
		*count += ft_putchar(va_arg(printf_arg, int));
	else if (str[i] == 's')
		*count += ft_putstr(va_arg(printf_arg, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		*count += ft_putnbr(va_arg(printf_arg, int));
	else if (str[i] == 'x')
		*count += ft_puthex(va_arg(printf_arg, unsigned int),
				"0123456789abcdef");
	else if (str[i] == 'X')
		*count += ft_puthex(va_arg(printf_arg, unsigned int),
				"0123456789ABCDEF");
	else if (str[i] == 'u')
		*count += ft_putunbr(va_arg(printf_arg, unsigned int));
	else if (str[i] == 'p')
		*count += ft_putptr(va_arg(printf_arg, void *), "0123456789abcdef");
	else if (str[i] == '%')
		*count += ft_putchar('%');
	return (i);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	printf_arg;

	va_start(printf_arg, str);
	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	while (str && str[i] != '\0')
	{
		if (str[i] == '%')
			i = ft_if(str, printf_arg, i, &count);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(printf_arg);
	return (count);
}
