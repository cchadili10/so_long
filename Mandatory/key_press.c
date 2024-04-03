/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:52:37 by hchadili          #+#    #+#             */
/*   Updated: 2024/04/03 17:00:30 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_img *img)
{
	img->old_plx = img->x_p;
	img->old_ply = img->y_p;
	if (keycode == 123 || keycode == 0)
		img->x_p -= 60;
	else if (keycode == 124 || keycode == 2)
		img->x_p += 60;
	else if (keycode == 125 || keycode == 1)
		img->y_p += 60;
	else if (keycode == 126 || keycode == 13)
		img->y_p -= 60;
	else if (keycode == 53)
		exit(0);
	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->imgb, 0, 0);
	ft_show(img, 0, keycode);
	if (img->old_plx != img->x_p || img->old_ply != img->y_p)
		img->move += 1;
	return (0);
}
