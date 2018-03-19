/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/03/19 19:13:54 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

#include <stdio.h>
#include <unistd.h>

#define Y fil->size.y
#define X fil->size.x

void	ft_init_plate(t_filler *fil)
{
	fil->tab = (char **)malloc(sizeof(char *) * (Y + 1));
	fil->tab[Y] = NULL;
	while (fil->tab[Y] != NULL)
	{
		*fil->tab = malloc(sizeof(char) * (X + 1));
		*fil->tab[X] = '\0';
		(*fil->tab)++;
	}
}

void	ft_get_plate(t_filler *fil)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (Y + 2));
	while (get_next_line(0, &tab[i]) > 0)
	{
		printf("i = %i\n", i);
		if (ft_isdigit(tab[i][0]))
		{
			j = 0;
			while (j <= X)
			{
				printf("j = %i\n", j);
				fil->tab[k][j] = tab[i][j + 4];
				j++;
			}
			k++;
		}
		i++;
	}
	tab[i] = NULL;
	i = 0;
	while (fil->tab[i] != NULL)
	{
		ft_putstr(fil->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_get_plate_size(t_filler *fil)
{
	char	**get_size;
	int		i;

	i = -1;
	get_size = (char **)malloc(sizeof(char *) * 10);
	while (i++ != 9)
		get_next_line(0, &get_size[i]);
	i = 0;
	while (!ft_isdigit(get_size[9][i]))
		i++;
	Y = ft_atoi(&get_size[9][i]);
	while (ft_isdigit(get_size[9][i]))
		i++;
	i++;
	X = ft_atoi(&get_size[9][i]);
	fil->player = ((ft_strstr(get_size[6], "apoque") != NULL) ? 1 : 2);
	printf("x = %i y = %i player = %i\n", X, Y, fil->player);
	i = -1;
	while (i++ != 9)
		free(get_size[i]);
	free(get_size);
	ft_init_plate(fil);
	ft_get_plate(fil);
}

int		main(void)
{
	t_filler	fil;

	ft_get_plate_size(&fil);
	return (0);
}
