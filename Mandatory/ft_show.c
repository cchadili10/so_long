/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:42:33 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/08 00:49:27 by hchadili         ###   ########.fr       */
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

void	ft_show_map(t_img *i, char c, int *ps_wall_x, int *ps_wall_y)
{
	if (c == '1')
	{
		mlx_put_image_to_window(i->mlx, i->win, i->imgw, i->x, i->y);
		*ps_wall_x = i->x;
		*ps_wall_y = i->y;
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
			{
				write(1, "you win\n", 9);
				ft_cross(i);
			}
		}
	}
}

void	ft_show_player_move(t_img *i, int b, char c)
{
	if (b)
		mlx_put_image_to_window(i->mlx, i->win, i->imgp, i->x_p, i->y_p);
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

void	ft_show(t_img *i, int n)
{
	int	x;
	int	ps_wall_x;
	int	ps_wall_y;

	x = 0;
	ps_wall_x = 0;
	ps_wall_y = 0;
	while (i->mapp[x])
	{
		if (i->mapp[x] == '1' || i->mapp[x] == 'E' || (i->mapp[x] == 'P' && n))
			ft_show_map(i, i->mapp[x], &ps_wall_x, &ps_wall_y);
		else if (i->mapp[x] == 'C' && (i->x_p == i->x && i->y_p == i->y))
			i->mapp[x] = '0';
		else if (i->mapp[x] == 'C')
			mlx_put_image_to_window(i->mlx, i->win, i->imgc, i->x, i->y);
		if (i->mapp[x] == '\n')
			ft_show_player_move(i, 0, i->mapp[x]);
		if (n == 0 && (i->x_p != ps_wall_x || i->y_p != ps_wall_y))
			ft_show_player_move(i, 1, i->mapp[x]);
		else if (n == 0 && (i->x_p == ps_wall_x || i->y_p == ps_wall_y))
			ft_show_player_move(i, 0, i->mapp[x]);
		x++;
		i->x += 60;
	}
	((1) && (i->x = 0, i->y = 0));
}
