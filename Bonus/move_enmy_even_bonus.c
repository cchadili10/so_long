/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enmy_even_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:07:21 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/06 21:49:38 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_change_position_even(t_img *i, int *x, int *dir, int check)
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
	else if (check == 1)
	{
		if (i->mapp[*x] == 'X' && (i->mapp[*x - 1] == '0'
				|| i->mapp[*x - 1] == 'P'))
		{
			i->mapp[*x] = '0';
			i->mapp[*x - 1] = 'X';
			(*x)++;
		}
		else
			*dir = 0;
	}
}

void	ft_for_even(t_img *i)
{
	int			x;
	int			check;
	int			car;
	static int	dir;

	x = 0;
	check = 0;
	car = ft_strlen(i->mapp) - 1;
	if (i->mapp[car] == '\n')
		check = 1;
	while (i->mapp[x])
	{
		if (dir == 0)
			ft_change_position_even(i, &x, &dir, 0);
		else if (dir == 1)
			ft_change_position_even(i, &x, &dir, 1);
		x++;
	}
	if (check)
	{
		if (dir)
			dir = 0;
		else
			dir = 1;
	}
}
