/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/04/03 20:17:50 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define X fil->piece_size.x
#define Y fil->piece_size.y

#include <stdio.h>

void		ft_free_struct(t_filler *fil, char** line)
{
	int	i;

	i = 0;
	if (fil->targets)
		free(fil->targets);
	if (fil->spots)
		free(fil->spots);
	while (i < fil->size.y)
	{
		if (fil->tab[i])
			free(fil->tab[i]);
		if (fil->nb[i])
			free(fil->nb[i]);
		i++;
	}
	if (fil->tab)
		free(fil->tab);
	if (fil->nb)
		free(fil->nb);
	//if (*line)
	//	free(*line);
	(void)line;
	i = 0;
	while (i < fil->piece_size.y)
	{
		if (fil->piece[i])
			free(fil->piece[i]);
		i++;
	}
	if (fil->piece)
		free(fil->piece);
	if (fil->piece_coor)
	{
		free(fil->piece_coor);
	}
}

void		ft_treat_piece2(t_filler *fil)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;

	while (j < X)
	{
		i = 0;
		while (i < Y)
		{
			if (fil->piece[i][j] == '*' && fil->piece_width == -1)
				fil->piece_width = j;
			else if (fil->piece[i][j] == '*')
				k = i;
			i++;
		}
		j++;
	}
	fil->piece_width = k - fil->piece_width + 1;
	//printf("piece x = %i y = %i\n", X, Y);
}

void		ft_treat_piece(t_filler *fil)
{
	int	i;
	int	j;
	int	k;

	fil->piece_height = -1;
	fil->piece_width = -1;
	i = -1;
	while (++i < Y)
	{
		j = -1;
		while (++j < X)
		{
			if (fil->piece[i][j] == '*' && fil->piece_height == -1)
				fil->piece_height = i;
			else if (fil->piece[i][j] == '*')
				k = i;
		}
	}
	fil->piece_height = k - fil->piece_height + 1;
	ft_treat_piece2(fil);
}
