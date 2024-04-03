/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:42:33 by hchadili          #+#    #+#             */
/*   Updated: 2024/04/03 16:52:57 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	look_for_coin(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == 'C')
			return (1);
		x++;
	}
	return (0);
}

void	ft_handel(t_img *i, char c, int *old_x, int *old_y)
{
	if (c == '1')
	{
		mlx_put_image_to_window(i->mlx, i->win, i->imgw, i->x, i->y);
		*old_x = i->x;
		*old_y = i->y;
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(i->mlx, i->win, i->imgp, i->x, i->y);
		i->x_p = i->x;
		i->y_p = i->y;
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(i->mlx, i->win, i->imgd, i->x, i->y);
		if (look_for_coin(i->mapp) == 0)
		{
			if (i->x == i->x_p && i->y == i->y_p)
				exit(0);
		}
	}
}

void	ft_complit(t_img *i, int key_c, int b, char c)
{
	if (b)
	{
		if (key_c == 123 || key_c == 0)
			mlx_put_image_to_window(i->mlx, i->win, i->imgp, i->x_p, i->y_p);
		else if (key_c == 124 || key_c == 2)
			mlx_put_image_to_window(i->mlx, i->win, i->imgp, i->x_p, i->y_p);
		else if (key_c == 125 || key_c == 1)
			mlx_put_image_to_window(i->mlx, i->win, i->imgp, i->x_p, i->y_p);
		else if (key_c == 126 || key_c == 13)
			mlx_put_image_to_window(i->mlx, i->win, i->imgp, i->x_p, i->y_p);
		else
			mlx_put_image_to_window(i->mlx, i->win, i->imgp, i->x_p, i->y_p);
	}
	else if (c == '\n')
	{
		i->y += 60;
		i->x = -60;
	}
	else
	{
		i->x_p = i->old_plx;
		i->y_p = i->old_ply;
	}
}

void	ft_set_zero(t_img *img)
{
	img->y = 0;
	img->x = 0;
}

void	ft_show(t_img *i, int n, int key_c)
{
	int	x;
	int	old_x;
	int	old_y;

	x = 0;
	old_x = 0;
	old_y = 0;
	while (i->mapp[x])
	{
		if (i->mapp[x] == '1' || i->mapp[x] == 'E' || (i->mapp[x] == 'P' && n))
			ft_handel(i, i->mapp[x], &old_x, &old_y);
		else if (i->mapp[x] == 'C' && (i->x_p != i->x || i->y_p != i->y))
			mlx_put_image_to_window(i->mlx, i->win, i->imgc, i->x, i->y);
		else if (i->mapp[x] == 'C' && (i->x_p == i->x && i->y_p == i->y))
			i->mapp[x] = '0';
		if (i->mapp[x] == '\n')
			ft_complit(i, key_c, 0, i->mapp[x]);
		if (n == 0 && (i->x_p != old_x || i->y_p != old_y))
			ft_complit(i, key_c, 1, i->mapp[x]);
		else if (n == 0 && (i->x_p == old_x || i->y_p == old_y))
			ft_complit(i, key_c, 0, i->mapp[x]);
		x++;
		i->x += 60;
	}
	ft_set_zero(i);
}
