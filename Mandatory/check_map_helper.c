/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:14 by hchadili          #+#    #+#             */
/*   Updated: 2024/04/03 01:05:03 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_helper(t_img *img, int *i, int *j, char *str)
{
	char	*s;
	int		sum;

	sum = 0;
	img->fd = open(str, O_RDONLY);
	if(img->fd == -1)
		ft_error();
	s = get_next_line(img->fd);
	sum = ft_strlenn(s);
	while (s)
	{
		*j = ft_strlenn(s);
		img->mapp = ft_strjoin(img->mapp, s);
		if (*j != sum)
			return (1);
		*i += 1;
		free(s);
		s = get_next_line(img->fd);
	}
	free(s);
	if (*i == *j)
		return (1);
	if (ft_check_map(img, *i, *j))
		return (1);
	return (0);
}
