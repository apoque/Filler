/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/03/19 19:13:54 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define X fil->size.x
#define Y fil->size.y
#define I fil->piece_size.y
#define J fil->piece_size.x
#define A fil->spots[i].x + fil->piece_coor[j].x - fil->piece_coor[k].x
#define B fil->spots[i].y + fil->piece_coor[j].y - fil->piece_coor[k].y
#include <stdio.h>

void			ft_get_piece_coor(t_filler *fil)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < I)
	{
		j = 0;
		while (j < J)
		{
			if (fil->piece[i][j] == '*')
			{
				fil->piece_coor[k].x = j;
				fil->piece_coor[k].y = i;
				k++;
			}
			j++;
		}
		i++;
	}
}

int				ft_check_place(t_filler *fil, int k, int i)
{
	int		j;
	short	error;

	j = 0;
	error = 0;
	while (fil->piece_coor[j].x >= 0 && error == 0)
	{
		if ((A > X || A < 0 || B > Y || B < 0 || fil->nb[B][A] != 0) && j != k)
			error = 1;
		j++;
	}
	if (error == 0)
		return (0);
	else
		return (1);
}

void			ft_place_piece(t_filler *fil)
{
	int	i;
	int	k;
	int	dist1;
	int	dist2;

	i = 0;
	dist1 = -1;
	dist2 = -1;
	while (fil->spots[i].x >= 0)
	{
		k = 0;
		while (fil->piece_coor[k].x >= 0)
		{
			//printf("yo %i\n", ft_check_place(fil, k, i));
			if (ft_check_place(fil, k, i) == 0)
			{
				dist2 = ft_get_dist(fil, k, i);
				if (dist2 < dist1 || dist1 < 0)
					{
						dist1 = dist2;
						fil->output.x = fil->spots[i].x - fil->piece_coor[k].x;
						fil->output.y = fil->spots[i].y - fil->piece_coor[k].y;
					}
			}
			k++;
		}
		i++;
	}
	if (dist1 == -1)
		ft_try_else(fil);;
}

void			ft_add_spot(t_filler *fil, int i, int j)
{
	int	exist;
	int	k;

	exist = 0;
	k = 0;
	while (fil->spots[k].x >= 0 && exist == 0)
	{
		if (fil->spots[k].y == i && fil->spots[k].x == j)
			exist = 1;
		k++;
	}
	if (exist == 0)
	{
		fil->spots[fil->nb_spots].x = j;
		fil->spots[fil->nb_spots].y = i;
		fil->nb_spots++;
	}
}

void			ft_spot_clear(t_filler *fil, int i, int j)
{
	if (i + 1 < Y && fil->nb[i + 1][j] == 0)
		ft_add_spot(fil, i, j);
	else if (i + 1 < Y && j + 1 < X && fil->nb[i + 1][j + 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i + 1 < Y && j - 1 < X && fil->nb[i + 1][j - 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i < Y && j + 1 < X && fil->nb[i][j + 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i < Y && j - 1 < X && fil->nb[i][j - 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i - 1 < Y && j < X && fil->nb[i - 1][j] == 0)
		ft_add_spot(fil, i, j);
	else if (i - 1 < Y && j + 1 < X && fil->nb[i - 1][j + 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i - 1 < Y && j - 1 < X && fil->nb[i - 1][j - 1] == 0)
		ft_add_spot(fil, i, j);
}
