/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:41:38 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/06 00:23:53 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlenn(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	return (x);
}

static int	ft_count_words(const char *s1, int c)
{
	int	x;
	int	check;
	int	res;

	x = 0;
	res = 0;
	check = 0;
	while (s1[x])
	{
		while (s1[x] != c && s1[x])
		{
			check = 1;
			x++;
		}
		if (check)
			res ++;
		check = 0;
		while (s1[x] == c && s1[x])
			x++;
	}
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	y;
	char	*array;

	y = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	array = (char *) malloc(len + 1);
	if (!array)
		return (0);
	while (len > y && s[y])
	{
		array[y] = s[start];
		start++;
		y++;
	}
	array[y] = '\0';
	return (array);
}

static char	**ft_fill(char **array, const char *s, char c, int count)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (count > x)
	{
		while (s[y] != c && s[y])
			y++;
		array[x] = ft_substr(s, 0, y);
		if (!array[x])
		{
			while (x--)
				free(array[x]);
			free(array);
			return (0);
		}
		while (s[y] == c && s[y])
			y++;
		s = s + y;
		y = 0;
		x++;
	}
	array[x] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;

	if (!s)
		return (0);
	count = ft_count_words(s, c);
	if (count == 0)
		return (0);
	array = (char **) malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (0);
	while (*s == c && *s)
		s++;
	array = ft_fill(array, s, c, count);
	return (array);
}
