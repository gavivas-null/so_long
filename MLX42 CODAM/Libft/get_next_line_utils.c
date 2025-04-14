/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:47:34 by gavivas-          #+#    #+#             */
/*   Updated: 2025/04/01 19:52:18 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	a;

	if (!s)
		return (0);
	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	size_t			a;
	unsigned char	l;

	l = c;
	a = 0;
	if (!s)
		return (NULL);
	while (s[a] != '\0' && s[a] != l)
		a++;
	if (s[a] == l)
		return ((char *)&s[a]);
	return (NULL);
}

char	*ft_gnl_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	s_len = ft_gnl_strlen(s);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_gnl_strlen(s1);
	size_s2 = ft_gnl_strlen(s2);
	str = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
