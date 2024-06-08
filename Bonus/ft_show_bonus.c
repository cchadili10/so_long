/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:42:33 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/08 00:45:25 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_is_player_win(t_img *i)
{
	if (look_for_coin(i->mapp))
		mlx_put_image_to_window(i->mlx, i->win, i->imgd, i->x, i->y);
	else if (look_for_coin(i->mapp) == 0)
	{
		mlx_put_image_to_window(i->mlx, i->win, i->imgcd, i->x, i->y);
		if (i->x == i->x_p && i->y == i->y_p)
		{
			write(1, "you win\n", 9);
			ft_cross(i);
		}
	}
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
	else if (c == 'X')
	{
		mlx_put_image_to_window(i->mlx, i->win, i->enmy, i->x, i->y);
		if (i->x == i->x_p && i->y == i->y_p)
		{
			write(1, "you lose\n", 10);
			ft_cross(i);
		}
	}
	else if (c == 'E')
		ft_is_player_win(i);
}

void	ft_show_player_move(t_img *i, int key_c, int b, char c)
{
	if (b)
	{
		if (key_c == 123 || key_c == 0)
			mlx_put_image_to_window(i->mlx, i->win, i->pl, i->x_p, i->y_p);
		else if (key_c == 124 || key_c == 2)
			mlx_put_image_to_window(i->mlx, i->win, i->pr, i->x_p, i->y_p);
		else if (key_c == 125 || key_c == 1)
			mlx_put_image_to_window(i->mlx, i->win, i->pd, i->x_p, i->y_p);
		else if (key_c == 126 || key_c == 13)
			mlx_put_image_to_window(i->mlx, i->win, i->pu, i->x_p, i->y_p);
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

void	ft_show(t_img *i, int n, int key_c)
{
	int	x;
	int	ps_wall_x;
	int	ps_wall_y;

	((1) && (x = 0, ps_wall_x = 0, ps_wall_y = 0));
	while (i->mapp[x])
	{
		if (i->mapp[x] == '1' || i->mapp[x] == 'E'
			|| i->mapp[x] == 'X' || (i->mapp[x] == 'P' && n))
			ft_show_map(i, i->mapp[x], &ps_wall_x, &ps_wall_y);
		else if (i->mapp[x] == 'C' && (i->x_p == i->x && i->y_p == i->y))
			i->mapp[x] = '0';
		else if (i->mapp[x] == 'C')
			mlx_put_image_to_window(i->mlx, i->win, i->imgc, i->x, i->y);
		if (i->mapp[x] == '\n')
			ft_show_player_move(i, key_c, 0, i->mapp[x]);
		if ((i->x_p != ps_wall_x || i->y_p != ps_wall_y) && n == 0)
			ft_show_player_move(i, key_c, 1, i->mapp[x]);
		else if ((i->x_p == ps_wall_x || i->y_p == ps_wall_y) && n == 0)
			ft_show_player_move(i, key_c, 0, i->mapp[x]);
		x++;
		i->x += 60;
	}
	((1) && (i->y = 0, i->x = 0));
}
