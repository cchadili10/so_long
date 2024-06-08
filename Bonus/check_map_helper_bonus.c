/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:14 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/07 22:10:20 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	look_for_err_map(char *s)
{
	int	x;
	int	y;
	int	j;
	int	k;

	((1) && (k = 0, y = 0, j = 0, x = 0));
	while (s[x])
	{
		if (s[x] != 'P' && s[x] != 'E' && s[x] != '0' && s[x] != 'X'
			&& s[x] != '1' && s[x] != 'C' && s[x] != '\n')
			ft_error("Error\ninvalid characters\n");
		if (s[x] == 'P')
			y++;
		if (s[x] == 'E')
			j++;
		if (s[x] == 'C')
			k++;
		x++;
	}
	if (y != 1 || j != 1 || k < 1)
		ft_error("Error\nduplicates characters or missing characters\n");
}

void	ft_read_map(t_img *img, int *i, int *j, char *str)
{
	char	*s;
	int		sum;

	img->fd = open(str, O_RDONLY);
	if (img->fd == -1)
		ft_error("Error\ninvalid file\n");
	s = get_next_line(img->fd);
	sum = ft_strlenn(s);
	while (s)
	{
		*j = ft_strlenn(s);
		img->mapp = ft_strjoin(img->mapp, s);
		if (*j != sum)
		{
			close(img->fd);
			free(s);
			ft_error("Error\ninvalid map\n");
		}
		*i += 1;
		free(s);
		s = get_next_line(img->fd);
	}
	close(img->fd);
	if ((*i * 60) > 1360 || (*j * 60) > 2560)
		ft_error("Error\nmap is big\n");
}
