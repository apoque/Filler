/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/04/03 20:40:22 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

#include <stdio.h>
#include <unistd.h>

#define Y fil->size.y
#define X fil->size.x
#define I fil->piece_size.x
#define J fil->piece_size.y

void		ft_get_piece(t_filler *fil, char *line)
{
	int		i;

	i = 0;
	while (!(ft_isdigit(line[i])))
		i++;
	fil->piece_size.y = ft_atoi(&(line[i]));
	while (ft_isdigit(line[i]))
		i++;
	fil->piece_size.x = ft_atoi(&(line[i]));
	i = 0;
	fil->piece = (char **)malloc(sizeof(char *) * (fil->piece_size.y));
	while (i < fil->piece_size.y)
	{
		if (get_next_line(0, &(fil->piece[i])) < 0)
			break;
		i++;
	}
	fil->piece_coor = (t_coor *)malloc(sizeof(t_coor) * I * J + 1);
	i = 0;
	while (i <= I * J)
	{
		fil->piece_coor[i].x = -1;
		fil->piece_coor[i].y = -1;
		i++;
	}
}

void		ft_init_plate(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	fil->tab = (char **)malloc(sizeof(char *) * Y);
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
}

void		ft_get_plate(t_filler *fil)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	get_next_line(0, &line);
	free(line);
	while (i < Y)
	{
		if (get_next_line(0, &fil->tab[i]) < 0)
			break;
		fil->tab[i] = ft_treat_tab(fil->tab[i]);
		j = 0;
		while (j < X && i < Y)
		{
			if (fil->tab[i][j] == 'o' || fil->tab[i][j] == 'O')
				fil->nb[i][j] = 1;
			else if (fil->tab[i][j] == 'x' || fil->tab[i][j] == 'X')
				fil->nb[i][j] = 2;
			j++;
		}
		i++;
	}
}

void		ft_get_plate_size(t_filler *fil, char *line)
{
	int		i;

	i = 0;
	fil->output.x = 0;
	fil->output.y = 0;
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
	ft_init_plate(fil);
	ft_get_plate(fil);
}

int		main(void)
{
	t_filler	fil;
	char		*line2;

	ft_bzero(&fil, sizeof(fil));
	fil.ok = 1;
	line2 = "";
	get_next_line(0, &line2);
	fil.player = (((!(ft_strstr(line2, "apoque.filler") == NULL)) && (!((ft_strstr(line2, "p1")) == NULL))) ? 1 : 2);
	fil.enemi = ((fil.player == 1) ? 2 : 1);
	free(line2);
	while (fil.ok == 1)
	{
		if (fil.ok == 0 || (get_next_line(0, &line2) <= 0))
			break;
		if (!(ft_strstr(line2, "Plateau") == NULL))
			ft_get_plate_size(&fil, line2);
		else if (!(ft_strstr(line2, "Piece") == NULL))
		{
			ft_get_piece(&fil, line2);
			ft_algo(&fil);
			dprintf(1, "%i %i\n", fil.output.y, fil.output.x);
		}
		free(line2);
	}
return (0);
}
