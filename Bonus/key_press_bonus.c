/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:52:37 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/04 18:22:08 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_direction(t_img *img, int keycode)
{
	if (keycode == 123 || keycode == 0)
	{
		img->x_p -= 60;
		img->old_key = keycode;
	}
	else if (keycode == 124 || keycode == 2)
	{
		img->x_p += 60;
		img->old_key = keycode;
	}
	else if (keycode == 125 || keycode == 1)
	{
		img->y_p += 60;
		img->old_key = keycode;
	}
	else if (keycode == 126 || keycode == 13)
	{
		img->y_p -= 60;
		img->old_key = keycode;
	}
	else if (keycode == 53)
		ft_cross(img);
}

int	key_press(int keycode, t_img *img)
{
	char	*s;

	img->old_plx = img->x_p;
	img->old_ply = img->y_p;
	ft_direction(img, keycode);
	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->imgb, 0, 0);
	ft_show(img, 0, img->old_key);
	s = ft_itoa(img->move);
	if (!s)
		ft_cross(img);
	if (img->old_plx != img->x_p || img->old_ply != img->y_p)
		img->move += 1;
	mlx_string_put(img->mlx, img->win, 0, 0, 0xFFFFFF, s);
	return (free(s), 0);
}
