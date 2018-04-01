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
#define I fil->piece_size.x
#define J fil->piece_size.y

int		ft_get_piece(t_filler *fil)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) <= 0)
		return (0);
	while (!(ft_isdigit(*line)))
		line++;
	fil->piece_size.y = ft_atoi(&(*line));
	line++;
	fil->piece_size.x = ft_atoi(&(*line));
	i = 0;
	fil->piece = (char **)malloc(sizeof(char *) * (fil->piece_size.y + 1));
	while (i < fil->piece_size.y)
	{
		if (get_next_line(0, &(fil->piece[i])) <= 0)
			return (0);
		i++;
	}
	fil->piece[i] = NULL;
	fil->piece_coor = (t_coor *)malloc(sizeof(t_coor) * I * J);
	i = 0;
	while (i <= I * J)
	{
		fil->piece_coor[i].x = -1;
		fil->piece_coor[i].y = -1;
		i++;
	}
	ft_treat_piece(fil);
	return (1);
}

int		ft_init_plate(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	fil->tab = (char **)malloc(sizeof(char *) * (Y + 1));
	fil->tab[Y] = NULL;
	while (i < Y)
	{
		fil->tab[i] = (char *)malloc(sizeof(char) * (X + 1));
		fil->tab[i][X] = '\0';
		i++;
	}
	i = 0;
	fil->nb = (int **)malloc(sizeof(int *) * Y);
	while (i < Y)
	{
		j = 0;
		fil->nb[i] = (int *)malloc(sizeof(int) * X);
		while (j < X)
		{
			fil->nb[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_get_plate(t_filler *fil)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (Y + 2));
	while (i <= Y)
	{
		if (get_next_line(0, &tab[i]) <= 0)
			return (0);
		if (ft_isdigit(tab[i][0]))
		{
			j = 0;
			while (j <= X)
			{
				fil->tab[k][j] = tab[i][j + 4];
				if (fil->tab[k][j] == 'o' || fil->tab[k][j] == 'O')
					fil->nb[k][j] = 1;
				else if (fil->tab[k][j] == 'x' || fil->tab[k][j] == 'X')
					fil->nb[k][j] = 2;
				j++;
			}
			k++;
		}
		i++;
	}
	fil->tab[i] = NULL;
	free(tab);
	return (1);
}

int		ft_get_plate_size(t_filler *fil)
{
	int		i;
	char	*line;

	i = 0;
	line = "";
	fil->output.x = 0;
	fil->output.y = 0;
	if (get_next_line(0, &line) <= 0)
		return (0);
	while (!ft_isdigit(line[i]))
		i++;
	Y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	X = ft_atoi(&line[i]);
	fil->targets = (t_coor *)malloc(sizeof(t_coor) * X * Y);
	fil->spots = (t_coor *)malloc(sizeof(t_coor) * X * Y);
	i = 0;
	while (i < X * Y)
	{
		fil->targets[i].x = -1;
		fil->targets[i].y = -1;
		fil->spots[i].x = -1;
		fil->spots[i].y = -1;
		i++;
	}
	return (1);
}

int		main(void)
{
	t_filler	fil;
	char		*line;

	ft_bzero(&fil, sizeof(fil));
	fil.ok = 1;
	line = "";
	/*while (ft_strstr(line, "Plateau") == NULL)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "apoque") != NULL)
		{
			if (ft_strstr(line, "1") != NULL)
				fil.player = 1;
			else if (ft_strstr(line, "2") != NULL)
				fil.player = 2;
		}
	}*/
	get_next_line(0, &line);
	fil.player = ((ft_strstr(line, "1") ? 1 : 2));
	fil.enemi = ((fil.player == 1) ? 2 : 1);
	while (1)
	{
		if (ft_get_plate_size(&fil) * ft_init_plate(&fil) * ft_get_plate(&fil) * ft_get_piece(&fil) == 1)
		ft_algo(&fil);
		else
			return (-1);
		printf("%i %i\n", fil.output.y, fil.output.x);
		//ft_free_struct(&fil);
	}
	return (0);
}
