/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:52:08 by hchadili          #+#    #+#             */
/*   Updated: 2024/04/03 17:07:29 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fool_fill(char **arr, int x, int y)
{
	if (arr[y][x] == '1' || arr[y][x] == 'L')
		return ;
	arr[y][x] = 'L';
	ft_fool_fill(arr, x + 1, y);
	ft_fool_fill(arr, x - 1, y);
	ft_fool_fill(arr, x, y + 1);
	ft_fool_fill(arr, x, y - 1);
}

int	look_for_err_map(char *s)
{
	int	x;
	int	y;
	int	j;
	int	k;

	((1) && (k = 0, y = 0, j = 0, k = 0, x = 0));
	while (s[x])
	{
		if (s[x] != 'P' && s[x] != 'E' && s[x] != '0'
			&& s[x] != '1' && s[x] != 'C' && s[x] != '\n')
			return (1);
		if (s[x] == 'P')
			y++;
		if (s[x] == 'E')
			j++;
		if (s[x] == 'C')
			k++;
		x++;
	}
	if (y != 1 || j != 1 || k < 1)
		return (1);
	return (0);
}

void	ft_get_pos_player(t_img *img, char **arr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 'P')
			{
				img->x_p = x;
				img->y_p = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	ft_is_valid(char **arr)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x] == 'C' || arr[y][x] == 'E' || arr[y][x] == 'P')
				return ((1));
			x++;
		}
		free(arr[y]);
		y++;
	}
	return ((0));
}

int	ft_check_map(t_img *img, int i, int j)
{
	char	**arr;
	int		x;
	int		y;

	arr = ft_split(img->mapp, '\n');
	x = 0;
	y = 0;
	while (arr[0][x])
	{
		if (arr[0][x] != '1' || arr[i - 1][x] != '1')
			return (1);
		x++;
	}
	while (arr[y])
	{
		if (arr[y][0] != '1' || arr[y][j - 1] != '1')
			return (1);
		y++;
	}
	ft_get_pos_player(img, arr);
	ft_fool_fill(arr, img->x_p, img->y_p);
	if (ft_is_valid(arr))
		return (free(arr), 1);
	return (free(arr), 0);
}
