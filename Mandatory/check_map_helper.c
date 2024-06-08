/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:14 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/07 22:10:20 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	look_for_err_map(char *s)
{
	int	x;
	int	cnt_p;
	int	cnt_e;
	int	cnt_c;

	((1) && (cnt_c = 0, cnt_p = 0, cnt_e = 0, cnt_c = 0, x = 0));
	while (s[x])
	{
		if (s[x] != 'P' && s[x] != 'E' && s[x] != '0'
			&& s[x] != '1' && s[x] != 'C' && s[x] != '\n')
			ft_error("Error\ninvalid characters\n");
		if (s[x] == 'P')
			cnt_p++;
		if (s[x] == 'E')
			cnt_e++;
		if (s[x] == 'C')
			cnt_c++;
		x++;
	}
	if (cnt_p != 1 || cnt_e != 1 || cnt_c < 1)
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
