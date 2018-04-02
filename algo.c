/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                           :+:      :+:    :+:   */
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
	if (i + 1 <= Y  && fil->nb[i + 1][j] == 0)
		ft_add_target(fil, i + 1, j);
	if (i + 1 <= Y && j + 1 <= X && fil->nb[i + 1][j + 1] == 0)
		ft_add_target(fil, i + 1, j + 1);
	if (i + 1 <= Y && j - 1 <= X && j - 1 >= 0 && fil->nb[i + 1][j - 1] == 0)
		ft_add_target(fil, i + 1, j - 1);
	if (i <= Y && j + 1 <= X && fil->nb[i][j + 1] == 0)
		ft_add_target(fil, i, j + 1);
	if (i <= Y && j - 1 <= X && j - 1 >= 0 && fil->nb[i][j - 1] == 0)
		ft_add_target(fil, i, j - 1);
	if (i - 1 <= Y && i - 1 >= 0 && j <= X && fil->nb[i - 1][j] == 0)
		ft_add_target(fil, i - 1, j);
	if (i - 1 <= Y && i - 1 >= 0 && j + 1 <= X && fil->nb[i - 1][j + 1] == 0)
		ft_add_target(fil, i - 1, j + 1);
	if (i - 1 <= Y && i - 1 >= 0 && j - 1 <= X && j - 1 >= 0 && fil->nb[i - 1][j - 1] == 0)
		ft_add_target(fil, i - 1, j - 1);
}

void			ft_get_targets(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	while (i < Y)
	{
		j = 0;
		while (j < X)
		{
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
	//int	j;

	i = 0;
	fil->nb_targets = 0;
	fil->nb_spots = 0;
	ft_get_targets(fil);
	ft_get_piece_coor(fil);
	/*printf("\n\nBOARD\n");
	while (i < fil->size.y)
	{
		j = 0;
		while (j < fil->size.x)
		{
			printf("%i", fil->nb[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("\nnb targets = %i nb spots = %i\n", fil->nb_targets, fil->nb_spots);
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
	}*/
	ft_place_piece(fil);
}
