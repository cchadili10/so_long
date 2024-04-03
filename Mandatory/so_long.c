/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:46:38 by hchadili          #+#    #+#             */
/*   Updated: 2024/04/03 02:12:45 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2,"Error\n",6);
	exit(0);
}
void	ft_look_ber(char *s)
{
	int	x;
	int	y;
	char *s1;
	
	s1 = ".ber";
	x = ft_strlen(s) - 1;
	y = ft_strlen(s1) - 1;
	while (y)
	{
		if (s[x] != s1[y])
			ft_error();
		x--;
		y--;
	}
	if(x == 0)
		ft_error();
}
int	main(int a, char *av[])
{
	t_img	img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (a == 1 || a > 2)
		ft_error();
	ft_look_ber(av[1]);
	if (ft_helper(&img, &i, &j, av[1]))
		ft_error();
	img.x = 0;
	img.y = 0;
	printf("i =  %d j = %d\n",i,j);
	ft_start(&img, j, i);
	printf("%s --\n",av[1]);
	mlx_put_image_to_window(img.mlx, img.win, img.imgb, 0, 0);
	ft_show(&img, 1, 0);
	mlx_string_put(img.mlx, img.win, 0, 0, 0xFFFFFF, ft_itoa(img.move));
	mlx_hook(img.win, 2, 0, key_press, &img);
	mlx_loop(img.mlx);
	return (0);
}
