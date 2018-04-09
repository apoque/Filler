/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/04/03 15:28:39 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define X fil->size.x
#define Y fil->size.y

#include <stdio.h>

void			ft_add_target(t_filler *fil, int i, int j)
{
	int	exist;
	int	k;

	exist = 0;
	k = 0;
	while (fil->targets[k].x >= 0 && exist == 0)
	{
		if (fil->targets[k].y == i && fil->targets[k].x == j)
			exist = 1;
		k++;
	}
	if (exist == 0)
	{
		fil->targets[fil->nb_targets].x = j;
		fil->targets[fil->nb_targets].y = i;
		fil->nb_targets++;
	}
}

void			ft_is_clear(t_filler *fil, int i, int j)
{
	if (i + 1 < Y  && fil->nb[i + 1][j] == 0)
		ft_add_target(fil, i + 1, j);
	if (i + 1 < Y && j + 1 < X && fil->nb[i + 1][j + 1] == 0)
		ft_add_target(fil, i + 1, j + 1);
	if (i + 1 < Y && j - 1 < X && j - 1 >= 0 && fil->nb[i + 1][j - 1] == 0)
		ft_add_target(fil, i + 1, j - 1);
	if (i < Y && j + 1 < X && fil->nb[i][j + 1] == 0)
		ft_add_target(fil, i, j + 1);
	if (i < Y && j - 1 < X && j - 1 >= 0 && fil->nb[i][j - 1] == 0)
		ft_add_target(fil, i, j - 1);
	if (i - 1 < Y && i - 1 >= 0 && j < X && fil->nb[i - 1][j] == 0)
		ft_add_target(fil, i - 1, j);
	if (i - 1 < Y && i - 1 >= 0 && j + 1 < X && fil->nb[i - 1][j + 1] == 0)
		ft_add_target(fil, i - 1, j + 1);
	if (i - 1 < Y && i - 1 >= 0 && j - 1 < X && j - 1 >= 0 && fil->nb[i - 1][j - 1] == 0)
		ft_add_target(fil, i - 1, j - 1);
}

void			ft_get_targets(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	//printf(" X= %i Y = %i\n", X, Y);
	while (i < Y)
	{
		//printf("%i\n", i);
		j = 0;
		while (j < X)
		{
			//printf("%i\n", j);
			if (fil->nb[i][j] == fil->enemi)
				ft_is_clear(fil, i, j);
			else if (fil->nb[i][j] == fil->player)
				ft_spot_clear(fil, i, j);
			j++;
		}
		i++;
	}

}

void			ft_algo(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	fil->nb_targets = 0;
	fil->nb_spots = 0;
	dprintf(2, "__A__\n");
	ft_get_targets(fil);
	dprintf(2, "__B__\n");
	ft_get_piece_coor(fil);
	dprintf(2, "__C__\n");
	dprintf(2, "\n\nBOARD\n");
	while (i < fil->size.y)
	{
		j = 0;
		while (j < fil->size.x)
		{
			dprintf(2, "%i", fil->nb[i][j]);
			j++;
		}
		dprintf(2, "\n");
		i++;
	}
	dprintf(2, "\n");
	dprintf(2, "\nnb targets = %i nb spots = %i\n", fil->nb_targets, fil->nb_spots);
	i = 0;
	while (fil->targets[i].x >= 0)
	{
		dprintf(2, "target n*%i: x = %i y = %i\n", i, fil->targets[i].x, fil->targets[i].y);
		i++;
	}
	i = 0;
	while (fil->spots[i].x >= 0)
	{
		dprintf(2, "spot n*%i: x = %i y = %i\n", i, fil->spots[i].x, fil->spots[i].y);
		i++;
	}
	if (fil->nb_spots > 0 && fil->nb_targets > 0)
	{
		dprintf(2, "AAAAAAAAAAAAAAA\n");
		ft_place_piece(fil);
	}
	if (fil-> nb_spots > 0 && fil->output.x == 0 && fil->output.y == 0)
	{
		dprintf(2, "BBBBBBBBBBBBBB\n");
		ft_try_else(fil);
	}
	dprintf(2, "CCCCCCCCCCCCCCCCC\n");
	//ft_free_struct(*fil);
}
