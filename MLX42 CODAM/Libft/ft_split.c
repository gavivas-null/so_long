/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavivas- <gavivas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:53:21 by gavivas-          #+#    #+#             */
/*   Updated: 2024/08/19 20:09:17 by gavivas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_copywords(char const *s, char c, int *i)
{
	char	*new;
	int		j;

	while (s[*i] != '\0' && s[*i] == c)
		(*i)++;
	j = *i;
	while (s[j] != '\0' && s[j] != c)
		j++;
	new = ft_substr(s, *i, j - *i);
	if (!new)
		return (NULL);
	*i = j;
	return (new);
}

static void	ft_free(char **new, int count)
{
	while (count >= 0)
	{
		free(new[count]);
		count--;
	}
	free(new);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**new;

	count = ft_countwords(s, c);
	new = ft_calloc(sizeof(char *), count + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		new[j] = ft_copywords(s, c, &i);
		if (!new[j])
			return (ft_free(new, j - 1), NULL);
		j++;
	}
	return (new);
}

/* 
int main(void)   //MAIN DE ft_countwords
{
    char *s = "asdg hoola c";
    char c = ' ';

    printf("%d \n", ft_limits(s, c));
    return 0;
} */
/* int	main(void) //MAIN DE ft_copywords
{
    char	*s = "hola hi";
    char	c = ' ';
	int	i = 2;

    printf(".%s.\n", ft_copywords(s, c, &i));
	printf(".%s.\n", ft_copywords(s, c, &i));
	return 0;
} */
/*
int	main(void)
{
	char	*s = "Hola Mi Gente";
	char	c = ' ';
 	char **splitt = ft_split(s, c);

	int i = 0;
	while (splitt[i])
	{
		ft_putstr_fd(splitt[i], 1);
		i++;
	}
	return 0;
}*/