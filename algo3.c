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

int				ft_get_dist(t_filler *fil, int k, int i)
{
	int	dist1;
	int	dist2;
	int	j;
	int	g;

	j = 0;
	dist1 = -1;
	while (fil->targets[j].x >= 0)
	{
		g = 0;
		while (fil->piece_coor[g].x >= 0)
		{
			dist2 = ft_power(fil->targets[j].x - (fil->spots[i].x + fil->piece_coor[g].x - fil->piece_coor[k].x) , 2) + ft_power(fil->targets[j].y - (fil->spots[i].y + fil->piece_coor[g].y - fil->piece_coor[k].y), 2);
			if (dist2 < dist1 || dist1 < 0)
				dist1 = dist2;
			g++;
		}
		j++;
	}
	return (dist1);
}
