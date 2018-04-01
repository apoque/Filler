/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/03/19 19:13:54 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define X fil->piece_size.x
#define Y fil->piece_size.y

#include <stdio.h>

void		ft_free_struct(t_filler *fil)
{
	int	i;

	i = 0;
	while (i < fil->size.y)
	{
		//free(fil->piece[i]);
		free(fil->tab[i]);
		free(fil->nb[i]);
		i++;
	}
	free(fil->piece);
	free(fil->tab);
	free(fil->nb);
	i = -1;
	free(fil->spots);
	free(fil->targets);
	free(fil->piece_coor);
}

void		ft_treat_piece2(t_filler *fil)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	k = 0;

	while (++j < X)
	{
		i = -1;
		while (++i < Y)
		{
			if (fil->piece[i][j] == '*' && fil->piece_width == -1)
				fil->piece_width = j;
			else if (fil->piece[i][j] == '*')
				k = i;
		}
	}
	fil->piece_width = k - fil->piece_width + 1;
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
