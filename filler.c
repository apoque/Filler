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

void		ft_free_struct(t_filler fil)
{
	int	i;

	i = 0;
	free(fil.targets);
	free(fil.spots);
	while (i < fil.size.y)
	{
		free(fil.tab[i]);
		free(fil.nb[i]);
		i++;
	}
	free(fil.tab);
	free(fil.nb);
	i = 0;
	while (i < fil.piece_size.y)
	{
		free(fil.piece[i]);
		i++;
	}
	free(fil.piece);
	free(fil.piece_coor);
}

char	*ft_treat_tab(char *line)
{
	char *tmp;

	tmp = ft_strdup(line + 4);
	if (line)
		free(line);
	line = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	return (line);
}
