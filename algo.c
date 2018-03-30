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

#define X fil->size.x
#define Y fil->size.y

#include <stdio.h>

void		ft_algo(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	fil->ok = 0;
	while (i < Y && fil->ok == 0)
	{
		j = 0;
		while (j < X && fil->ok == 0)
		{
			if (fil->player == fil->nb[i][j])
			{
				fil->output.x = j;
				fil->output.y = i;
				fil->ok = 1;
			}
			j++;
		}
		i++;
	}
}
