/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/04/03 15:29:19 by apoque           ###   ########.fr       */
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
	dprintf(2, "YOOOOOOOOOO\nJ = %i\n", J);
	/*while (i < I)
	{
		dprintf(2, "%s\n", fil->piece[i]);
		i++;
	}
	i = 0;*/
	dprintf(2, "__M__\n");
	while (i < I)
	{
		dprintf(2, "__N__\n");
		j = 0;
		while (j < J)
		{
			dprintf(2, "__O__\n");
			if (fil->piece[i][j] == '*')
			{
				dprintf(2, "__P__\n");
				fil->piece_coor[k].x = j;
				fil->piece_coor[k].y = i;
				k++;
			}
			j++;
		}
		i++;
	}
	dprintf(2, "__Q__\n");
	/*i = 0;
	while (fil->piece_coor[i].x > 0)
	{
		printf("piece n*%i: x = %i y = %i\n", i, fil->piece_coor[i].x, fil->piece_coor[i].y);
		i++;
	}*/
}

int				ft_check_place(t_filler *fil, int k, int i)
{
	int		j;
	short	error;

	j = 0;
	error = 0;
	while (fil->piece_coor[j].x >= 0 && error == 0)
	{
		if ((A >= X || A < 0 || B >= Y || B < 0 || fil->nb[B][A] != 0) && j != k)
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
	/*while (fil->piece_coor[i].x >= 0)
	{
		printf("piece_coor n*%i: x = %i y = %i\n", i, fil->piece_coor[i].x, fil->piece_coor[i].y);
		i++;
	}
	i = 0;*/
	while (fil->spots[i].x >= 0)
	{
		k = 0;
		while (fil->piece_coor[k].x >= 0)
		{
			//printf("spot = %i piece coor = %i place =  %i\n", i, k, ft_check_place(fil, k, i));
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
	if (i + 1 < Y  && fil->nb[i + 1][j] == 0)
		ft_add_spot(fil, i, j);
	else if (i + 1 < Y && j + 1 < X && fil->nb[i + 1][j + 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i + 1 < Y && j - 1 < X && j - 1 >= 0 && fil->nb[i + 1][j - 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i < Y && j + 1 < X && fil->nb[i][j + 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i < Y && j - 1 < X && j - 1 >= 0 && fil->nb[i][j - 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i - 1 < Y && i - 1 >= 0 && j < X && fil->nb[i - 1][j] == 0)
		ft_add_spot(fil, i, j);
	else if (i - 1 < Y && i - 1 >= 0 && j + 1 < X && fil->nb[i - 1][j + 1] == 0)
		ft_add_spot(fil, i, j);
	else if (i - 1 < Y && i - 1 >= 0 && j - 1 < X && j - 1 >= 0 && fil->nb[i - 1][j - 1] == 0)
		ft_add_spot(fil, i, j);
	}
