/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:52:08 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/06 00:31:49 by hchadili         ###   ########.fr       */
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

void	ft_is_valid(char **arr)
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
			{
				ft_free_arr(arr);
				ft_error("Error\ninvalid phat\n");
			}
			x++;
		}
		y++;
	}
	ft_free_arr(arr);
}

void	ft_for_flood(t_img *img, char **arr)
{
	ft_get_pos_player(img, arr);
	ft_fool_fill(arr, img->x_p, img->y_p);
	ft_is_valid(arr);
}

void	ft_check_map(t_img *img, int i, int j)
{
	char	**arr;
	int		x;
	int		y;

	arr = ft_split(img->mapp, '\n');
	if (!arr)
		ft_error("Error\nmalloc fail\n");
	((1) && (x = -1, y = -1));
	while (arr[0][++x])
	{
		if (arr[0][x] != '1' || arr[i - 1][x] != '1')
		{
			ft_free_arr(arr);
			ft_error("Error\ninvalid map\n");
		}
	}
	while (arr[++y])
	{
		if (arr[y][0] != '1' || arr[y][j - 1] != '1')
		{
			ft_free_arr(arr);
			ft_error("Error\ninvalid map\n");
		}
	}
	ft_for_flood(img, arr);
}
