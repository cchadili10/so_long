/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:46:38 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/07 22:10:20 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

int	ft_cross(t_img *img)
{
	ft_des_img(img);
	exit(0);
}

void	ft_look_ber(char *s)
{
	int		x;
	int		y;
	char	*s1;

	s1 = ".ber";
	x = ft_strlen(s) - 1;
	y = ft_strlen(s1) - 1;
	while (y >= 0)
	{
		if (s[x] != s1[y])
			ft_error("Error\nfile should have .ber extension\n");
		x--;
		y--;
	}
}

int	main(int a, char *av[])
{
	t_img	img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (a == 1 || a > 2)
		ft_error("Error\nput valid argumets\n");
	ft_setzero(&img);
	ft_look_ber(av[1]);
	ft_read_map(&img, &i, &j, av[1]);
	look_for_err_map(img.mapp);
	ft_check_map(&img, i, j);
	ft_start(&img, j, i);
	mlx_put_image_to_window(img.mlx, img.win, img.imgb, 0, 0);
	ft_show(&img, 1);
	mlx_hook(img.win, 2, 0, key_press, &img);
	mlx_hook(img.win, 17, 0, ft_cross, &img);
	mlx_loop(img.mlx);
	return (0);
}
