/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enmy_odd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:05:40 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/07 18:26:08 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_change_position_odd(t_img *i, int *x, int *dir, int check)
{
	if (check == 0)
	{
		if (i->mapp[*x] == 'X' && (i->mapp[*x + 1] == '0'
				|| i->mapp[*x + 1] == 'P' ))
		{
			i->mapp[*x] = '0';
			i->mapp[*x + 1] = 'X';
			(*x)++;
		}
		else
			*dir = 1;
	}
	else
	{
		if (i->mapp[*x] == 'X' && (i->mapp[*x - 1] == '0'
				|| i->mapp[*x - 1] == 'P' ))
		{
			i->mapp[*x] = '0';
			i->mapp[*x - 1] = 'X';
			(*x)++;
		}
		else
			*dir = 0;
	}
}

void	ft_for_odd(t_img *i)
{
	int			x;
	int			car;
	int			check;
	static int	dir;

	((1) && (x = -1, check = 0));
	car = ft_strlen(i->mapp) - 1;
	if (i->mapp[car] == '\n' && (i->size_of_colum % 2) == 0)
		check = 1;
	if (i->mapp[car] != '\n' && (i->size_of_colum % 2) != 0)
		check = 1;
	while (i->mapp[++x])
	{
		if (dir == 0)
			ft_change_position_odd(i, &x, &dir, 0);
		else
			ft_change_position_odd(i, &x, &dir, 1);
	}
	if (check)
	{
		if (dir)
			dir = 0;
		else
			dir = 1;
	}
}
