/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:46:38 by hchadili          #+#    #+#             */
/*   Updated: 2024/01/13 15:15:24 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	perror("error");
	exit(0);
}

int	main(int a, char *av[])
{
	t_img	img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_helper(&img, &i, &j))
		ft_error();
	img.x = 0;
	img.y = 0;
	ft_start(&img, j, i);
	if (!img.imgb || !img.imgp || !img.imgc
		|| !img.imgw || !img.imgd || !img.imgcd)
		return (1);
	mlx_put_image_to_window(img.mlx, img.win, img.imgb, 0, 0);
	ft_show(&img, 1, 0);
	mlx_string_put(img.mlx, img.win, 0, 0, 0xFFFFFF, ft_itoa(img.move));
	mlx_hook(img.win, 2, 0, key_press, &img);
	mlx_loop(img.mlx);
	return (0);
}